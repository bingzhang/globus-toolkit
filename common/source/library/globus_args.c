/* globus_args.c : implements the Globus command-line parsing utility.
                   check globus_args.h for more detailed information.
*/

#include "config.h"
#include "globus_common_internal.h"
#include "globus_args.h"
#include "globus_libc.h"
#include "globus_fifo.h"
#include GLOBUS_THREAD_INCLUDE

#define globus_l_args_malloc(type,n)  (type *) globus_malloc(n * sizeof(type))


/* ----------------------------------------------------------------------
   globus_l_args_create_msg()
   
   creates (and possibly prints) a message
   ---------------------------------------------------------------------- */

int
globus_l_args_create_msg( char **         msg_storage,
			  char *          message    )
{
    if (msg_storage)
	*msg_storage = message;
    else
	globus_libc_fprintf( stderr, message );

    return GLOBUS_SUCCESS;
}

/* ----------------------------------------------------------------------
   globus_l_args_create_error_msg()
   
   creates (and possibly prints) an error message
   ---------------------------------------------------------------------- */

int
globus_l_args_create_error_msg( char **        error_msg,
				int            current_argc,
				char *         current_argv,
				char *         error_string,
				const char *   oneline_usage )
{
    char *      my_error_string;
    char *      p;
    char *      q;
    int         usage_len;
    int         len;


#define error_format    "\nError, argument #%d (%s) : %s\n\nSyntax : "
#define error_epilogue  "\n\nUse -help to display full usage.\n"

    my_error_string = (error_string) ? error_string : "(no error message)";

    len = strlen(error_format)
        + strlen(current_argv)
        + strlen(my_error_string)
        + strlen(oneline_usage)
        + strlen(error_epilogue)
	+ 10;

    p = globus_l_args_malloc( char, len );
    globus_assert( p );
    globus_libc_sprintf( p,
			 error_format, 
			 current_argc, 
			 current_argv,
			 my_error_string  );

    /* enforce one-line usage */
    q = strchr( oneline_usage, '\n' );
    if (q)
	usage_len = (int)(q - oneline_usage);
    else
	usage_len = strlen( oneline_usage );

    len = strlen(p);
    strncpy( &p[len], oneline_usage, usage_len );
    sprintf( &p[len+usage_len], error_epilogue );

    if (error_msg)
	*error_msg = p;
    else
    {
	globus_libc_fprintf( stderr, p );
	free(p);
    }

    return GLOBUS_SUCCESS;
}


/* ---------------------------------------------------------------------
   globus_l_args_validate()

   validates the predicates (values) of an option. if successful,
   allocates and returns 'values', pointing to the (option->arity)
   predicates.

   This function is only used in the inner loop in globus_args_scan():
   the code was taken out of there for easier overlook.
*/


int
globus_l_args_validate( globus_args_option_descriptor_t *   option, 
			int                                 start_argc,
			char **                             argv,
			char ***                            values,
			const char *                        oneline_usage,
			char **                             msg_storage  )
{
    int           rc;
    int           i;
    void *        p;
    char *        argp;
    char *        validation_error;

    *values = globus_l_args_malloc(char*, option->arity);
    globus_assert(*values);
    
    rc = GLOBUS_SUCCESS;

    for (i=0; !rc && i<option->arity; i++)
    {
	argp = argv[start_argc+1+i];
	if (option->tests && option->tests[i] )
	{
	    p = GLOBUS_NULL;
	    if ( option->test_parms && option->test_parms[i] )
		p = option->test_parms[i];

	    validation_error = GLOBUS_NULL;
	    rc = option->tests[i]( argp,
				   p,
				   &validation_error );

	    /* API defines non-zero return as an error */
	    if (rc)
	    {
		globus_l_args_create_error_msg( msg_storage,
						start_argc+1+i,
						argp,
						validation_error,
						oneline_usage   );
		continue;
	    }
	} /* if */

	(*values)[i] = argp;

    }   /* for */

    if (rc)
	free(*values);

    return rc;
}



/* ---------------------------------------------------------------------
   globus_l_args_add_instance()
   
   help function : creates an option instance and inserts in the fifo list.
*/
   

int
globus_l_args_add_instance( globus_fifo_t *                     fifo,
			    globus_args_option_descriptor_t *   option,
			    char **                             values )
{
    globus_args_option_instance_t *  t;

    t = globus_l_args_malloc( globus_args_option_instance_t , 1 );
    globus_assert( t );
    t->id_number = option->id_number;
    t->arity = option->arity;
    t->values = values;

    globus_fifo_enqueue( fifo, t );

    return GLOBUS_SUCCESS;
}



/* -------------------------------------------------------------------------
   globus_l_args_check_options()

   (7) The argument flags "-help", "-usage", and "-version" are reserved, and
       if they are detected the library will create an appropriate message 
       and signal an error.

*/

int
globus_l_args_check_options(
    int                                 option_count,
    globus_args_option_descriptor_t *   options     ,
    char **                             error_msg   )
{
#  define ERROR7   "Error : flags -help, -usage and -version are reserved.\n"
#  define ERRORID0 "Error : id_number 0 is reserved for unflagged arguments.\n"

    char **     alias;
    int         i;
    int         rc;

    rc = GLOBUS_SUCCESS;
    for (i=0; !rc && i<option_count; i++)
    {        
	if (options[i].id_number == 0)
	{
	    globus_l_args_create_msg( error_msg, ERRORID0 );
	    rc = GLOBUS_FAILURE;
	}
	else
	{
	    for (alias=options[i].names; (*alias); alias++)
	    {
		if (!strcmp(*alias, "-help")   ||
		    !strcmp(*alias, "-usage")  ||
		    !strcmp(*alias, "-version") )
		{
		    globus_l_args_create_msg( error_msg, ERROR7 );
		    rc = GLOBUS_FAILURE;
		    break;
		}
	    }
	}
    }

    return rc;
}



/* -------------------------------------------------------------------------
   globus_args_scan()

   NOTE: this implementation makes the assumption that a globus_fifo is
   built by globus_list_t. It returns the head of the fifo as 'options_found'

*/

int 
globus_args_scan(
    int  *                                argc,
    char ***                              argv,
    int                                   option_count,
    globus_args_option_descriptor_t  *    options,
    const char *                          name,
    const char *                          version,
    const char *                          oneline_usage,
    const char *                          long_usage,
    globus_list_t **                      options_found,
    char **                               error_msg    )
{
    static globus_mutex_t   args_mutex;
    static globus_bool_t    args_mutex_initialized = GLOBUS_FALSE;
    int                     rc;
    int                     my_argc;
    char *                  my_arg;
    int                     len;
    int                     i;
    char                    buf[40];
    char **                 alias;
    char **                 arglist;
    globus_fifo_t           fifo;
    globus_bool_t           done;
    globus_bool_t           found;

    globus_libc_lock();
    if (!args_mutex_initialized)
    {
	globus_mutex_init(&args_mutex,
			  (globus_mutexattr_t *) GLOBUS_NULL);
	args_mutex_initialized = GLOBUS_TRUE;
    }
    globus_libc_unlock();    

    globus_mutex_lock(&args_mutex);

    rc = GLOBUS_SUCCESS;
    globus_fifo_init(&fifo);
    *options_found = GLOBUS_NULL;
    if (error_msg)
	*error_msg = GLOBUS_NULL;

    /* precheck : are the options correct? */
    rc = globus_l_args_check_options(option_count, options, error_msg);
    done = (rc==GLOBUS_SUCCESS) ? GLOBUS_FALSE : GLOBUS_TRUE;

    my_argc=1;
    while (!done)
    {
        /* any more options? */ 
        if (my_argc == *argc)
        {
            done=GLOBUS_TRUE;
            continue;
        }

        my_arg = (*argv)[my_argc];
        len = strlen(my_arg);

        if (my_arg[0]!='-' || len<2)
        {
	    /* unrecognized option */
            done=GLOBUS_TRUE;
            continue;
        }

        /* '--*' is a special case : if '*' is non-null, it's an error.
            Otherwise, it signals end of parsing. */
        if (!strncmp(my_arg,"--",2))
        {
            if (len == 2)  /* end of parsing */
            {
                /* next argument is first "unrecognized" option */
                my_argc++;
            }
            else
            {
                rc = GLOBUS_FAILURE;
                globus_l_args_create_error_msg(
		    error_msg,
		    my_argc,
		    my_arg,
		    "double-dashed option syntax is not allowed",
		    oneline_usage                               );
            }
            done = GLOBUS_TRUE;
            continue;
        }

        /* three specials : -help, -usage, -version */
        if (!strcmp("-help",my_arg) || !strcmp("-usage",my_arg))
        {
            globus_l_args_create_msg( error_msg ,
				      (char *) long_usage );
	    rc = GLOBUS_FAILURE;
            done = GLOBUS_TRUE;
            continue;
        }
        if (!strcmp("-version",my_arg))
        {
	    globus_libc_sprintf( buf,
				 "%s %s",
				 name, version);
	    
            globus_l_args_create_msg( error_msg , buf );
	    rc = GLOBUS_FAILURE;
            done = GLOBUS_TRUE;
            continue;
        }
        
        /* is it a known flag? */
        found=GLOBUS_FALSE;
        for (i=0; !found && !rc && i<option_count; i++)
        {
            for (alias=options[i].names; !found && !rc && *alias; alias++)
            {
                if (!strcmp(my_arg, *alias))
                {
                    found = GLOBUS_TRUE;
                    arglist = GLOBUS_NULL;
                    if (options[i].arity > 0)
                    {
                        if (my_argc+options[i].arity >= *argc)
                        {
                            globus_l_args_create_error_msg(
				error_msg,
				my_argc,
				my_arg,
				"not enough arguments",
				oneline_usage  );

                            rc = GLOBUS_FAILURE;
                            continue;
                        }

			rc = globus_l_args_validate( &options[i],
						     my_argc,
						     (*argv),
						     &arglist,
						     oneline_usage,
						     error_msg    );
                    } /* if */

                    if (rc==GLOBUS_SUCCESS)
                    {
			/* option successfully detected: add it */
                        globus_l_args_add_instance( &fifo,
                                                    &options[i],
                                                    arglist );
                        my_argc += 1+options[i].arity;
                    }
                }           /* strcmp(my_arg,*alias)) */
            }               /* alias */
        }                   /* i */
	if (!found)
	{
	    /* my_arg contains an unregistered option */
	    rc = GLOBUS_FAILURE;
	    globus_l_args_create_error_msg( error_msg,
					    my_argc,
					    my_arg,
					    "unknown option",
					    oneline_usage  );
	}
        if (rc!=GLOBUS_SUCCESS)
        {
            done = GLOBUS_TRUE;
            continue;
        }
    } /* while (!done) */

    if (rc==GLOBUS_SUCCESS)
    {
	/* if successful, return number of options found */
	rc = globus_fifo_size(&fifo);

	/* modify argc/argv */
	if (my_argc>1)
	{
	    for (i = my_argc; i < *argc; i++)
		(*argv)[i-my_argc+1] = (*argv)[i];

	    *argc -= my_argc - 1;
	}
    }
    else
	rc = -1;   /* ensure negative return value for non-success */

    globus_mutex_unlock(&args_mutex);
    return rc;
}
/* globus_args_scan() */




/* ----------------------------------------------------------------------------
   globus_args_option_instance_list_free()

   Frees a list of globus_args_option_instance_t. A normal
   globus_list_free() is not enough as the struct contains a dynamically
   allocated entry 'values'.

*/

void
globus_args_option_instance_list_free( globus_list_t **  list )
{
    globus_args_option_instance_t  *   t;
    globus_list_t                  *   rest;
    
    for ( rest=*list;
	  !globus_list_empty(rest);
	  rest=globus_list_rest(rest) )
    {
	t = (globus_args_option_instance_t *) globus_list_first(rest);
	globus_assert(t);
	if (t->values)
	    free( t->values );
    }

    globus_list_free( *list );
    *list = GLOBUS_NULL;
    
    return;
}


/* ----------------------------------------------------------------------------
    globus_validate_int()

    validates if 'value' is an integer (oct,dec,hex) and optionally if it
    is within the range specified by '*parms'.
*/

/* error messages */

static char * globus_l_validate_error_null_parms
        = "test function 'parms' is a null pointer";

static char *  globus_l_validate_error_not_an_int
        = "value is not an integer";

static char *  globus_l_validate_error_range_type
        = "'range_type' in provided globus_validate_int_parms_t is invalid";

static char    globus_l_validate_error_buf[40];


int
globus_validate_int( char *         value,
                     void *         parms,
                     char **        error_msg )
{
    int                             val;
    char *                          format;
    globus_validate_int_parms_t *   range;

    if (!parms)
    {
	*error_msg = globus_l_validate_error_null_parms;
	return GLOBUS_FAILURE;
    }

    format = "%d";
    range = (globus_validate_int_parms_t *) parms;

    /* if the string starts with '0', then it's octal or hex */
    /* if the string starts with '0x' or '0X', then it's hex */
    if ( value[0] == '0' )
    {
        format = "%o";
        if ( !strncmp(value, "0x",2) || !strncmp(value, "0X",2) )
            format = "%x";
    }

    if ( !sscanf(value, format, &val ) )
    {
        *error_msg = globus_l_validate_error_not_an_int;
        return GLOBUS_FAILURE;
    }

    if (range->range_type == GLOBUS_VALIDATE_INT_NOCHECK)
        return GLOBUS_SUCCESS;

    if (!(range->range_type & GLOBUS_VALIDATE_INT_MINMAX))
    {
        *error_msg = globus_l_validate_error_range_type;
        return GLOBUS_FAILURE;
    }
    if ((range->range_type & GLOBUS_VALIDATE_INT_MIN) &&
        (range->range_min > val))
    {
	globus_libc_sprintf(globus_l_validate_error_buf,
			    "value is smaller than allowed min=%d",
			    range->range_min);
	*error_msg = globus_l_validate_error_buf;
        return GLOBUS_FAILURE;
    }
    if ((range->range_type & GLOBUS_VALIDATE_INT_MAX) &&
        (range->range_max < val))
    {
	globus_libc_sprintf(globus_l_validate_error_buf,
			    "value is larger than allowed max=%d",
			    range->range_max);
        *error_msg = globus_l_validate_error_buf;
        return GLOBUS_FAILURE;
    }

    return GLOBUS_SUCCESS;
}


/* ----------------------------------------------------------------------------
    globus_validate_filename()

    validates if a filename 'value' exists and can be opened in the mode
    specified by '*parms'.

*/

int
globus_validate_filename( char *    value,
                          void *    parms,
                          char **   error_msg )
{
    int            fd;
    int            mode;
    int            my_errno;

    if (!parms)
    {
	*error_msg = globus_l_validate_error_null_parms;
	return GLOBUS_FAILURE;
    }

    mode = *((int *)(parms));
    fd = globus_libc_open( value, mode );
    my_errno = errno;
    if (fd < 0)
    {
	*error_msg = globus_libc_system_error_string(my_errno);
	return GLOBUS_FAILURE;
    }

    globus_libc_close(fd);

    return GLOBUS_SUCCESS;
}


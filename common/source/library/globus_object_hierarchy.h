
#ifndef GLOBUS_OBJECT_HIERARCHY_H
#define GLOBUS_OBJECT_HIERARCHY_H

#include "config.h"
#include "globus_common_types.h"
#include "globus_object.h"
#include "globus_list.h"

EXTERN_C_BEGIN

/* the following code all generated by running the script
 * ./globus_object_hierarchy.h.sh declarations < globus_object_hierarchy.idl
 */

extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_RESOURCE_DEFINITION;

#define GLOBUS_OBJECT_TYPE_RESOURCE \
        (&GLOBUS_OBJECT_TYPE_RESOURCE_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_RESOURCE   */
extern globus_object_t *
globus_object_construct_resource (
);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_RESOURCE   */
extern globus_object_t *
globus_object_initialize_resource (
    globus_object_t * object
);


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_COMPUTER_DEFINITION;

#define GLOBUS_OBJECT_TYPE_COMPUTER \
        (&GLOBUS_OBJECT_TYPE_COMPUTER_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_COMPUTER   */
extern globus_object_t *
globus_object_construct_computer (
    char * computer_hostname);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_COMPUTER   */
extern globus_object_t *
globus_object_initialize_computer (
    globus_object_t * object,
    char * computer_hostname);

/* return the computer_hostname instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_COMPUTER   */
extern char *
globus_object_computer_get_computer_hostname (globus_object_t * object)
;

/* set the computer_hostname instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_COMPUTER   */
extern void
globus_object_computer_set_computer_hostname (
    globus_object_t * object,
    char * value)
;


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_GRAM_RESOURCE_DEFINITION;

#define GLOBUS_OBJECT_TYPE_GRAM_RESOURCE \
        (&GLOBUS_OBJECT_TYPE_GRAM_RESOURCE_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_GRAM_RESOURCE   */
extern globus_object_t *
globus_object_construct_gram_resource (
    char * computer_hostname,
    char * gram_resource_contact);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_GRAM_RESOURCE   */
extern globus_object_t *
globus_object_initialize_gram_resource (
    globus_object_t * object,
    char * computer_hostname,
    char * gram_resource_contact);

/* return the gram_resource_contact instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_GRAM_RESOURCE   */
extern char *
globus_object_gram_resource_get_gram_resource_contact (globus_object_t * object)
;

/* set the gram_resource_contact instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_GRAM_RESOURCE   */
extern void
globus_object_gram_resource_set_gram_resource_contact (
    globus_object_t * object,
    char * value)
;


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_FD_TABLE_DEFINITION;

#define GLOBUS_OBJECT_TYPE_FD_TABLE \
        (&GLOBUS_OBJECT_TYPE_FD_TABLE_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_FD_TABLE   */
extern globus_object_t *
globus_object_construct_fd_table (
);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_FD_TABLE   */
extern globus_object_t *
globus_object_initialize_fd_table (
    globus_object_t * object
);


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_STORAGE_DEFINITION;

#define GLOBUS_OBJECT_TYPE_STORAGE \
        (&GLOBUS_OBJECT_TYPE_STORAGE_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_STORAGE   */
extern globus_object_t *
globus_object_construct_storage (
    long storage_size);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_STORAGE   */
extern globus_object_t *
globus_object_initialize_storage (
    globus_object_t * object,
    long storage_size);

/* return the storage_size instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_STORAGE   */
extern long
globus_object_storage_get_storage_size (globus_object_t * object)
;

/* set the storage_size instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_STORAGE   */
extern void
globus_object_storage_set_storage_size (
    globus_object_t * object,
    long value)
;


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_FILE_DEFINITION;

#define GLOBUS_OBJECT_TYPE_FILE \
        (&GLOBUS_OBJECT_TYPE_FILE_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_FILE   */
extern globus_object_t *
globus_object_construct_file (
    long storage_size,
    char * file_filename,
    int file_fd,
    FILE* file_filep);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_FILE   */
extern globus_object_t *
globus_object_initialize_file (
    globus_object_t * object,
    long storage_size,
    char * file_filename,
    int file_fd,
    FILE* file_filep);

/* return the file_filename instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_FILE   */
extern char *
globus_object_file_get_file_filename (globus_object_t * object)
;

/* set the file_filename instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_FILE   */
extern void
globus_object_file_set_file_filename (
    globus_object_t * object,
    char * value)
;

/* return the file_fd instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_FILE   */
extern int
globus_object_file_get_file_fd (globus_object_t * object)
;

/* set the file_fd instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_FILE   */
extern void
globus_object_file_set_file_fd (
    globus_object_t * object,
    int value)
;

/* return the file_filep instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_FILE   */
extern FILE*
globus_object_file_get_file_filep (globus_object_t * object)
;

/* set the file_filep instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_FILE   */
extern void
globus_object_file_set_file_filep (
    globus_object_t * object,
    FILE* value)
;


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_MEMORY_DEFINITION;

#define GLOBUS_OBJECT_TYPE_MEMORY \
        (&GLOBUS_OBJECT_TYPE_MEMORY_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_MEMORY   */
extern globus_object_t *
globus_object_construct_memory (
    long storage_size);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_MEMORY   */
extern globus_object_t *
globus_object_initialize_memory (
    globus_object_t * object,
    long storage_size);


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_BUFFER_POOL_DEFINITION;

#define GLOBUS_OBJECT_TYPE_BUFFER_POOL \
        (&GLOBUS_OBJECT_TYPE_BUFFER_POOL_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_BUFFER_POOL   */
extern globus_object_t *
globus_object_construct_buffer_pool (
    long storage_size);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_BUFFER_POOL   */
extern globus_object_t *
globus_object_initialize_buffer_pool (
    globus_object_t * object,
    long storage_size);


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_COMMUNICATOR_DEFINITION;

#define GLOBUS_OBJECT_TYPE_COMMUNICATOR \
        (&GLOBUS_OBJECT_TYPE_COMMUNICATOR_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_COMMUNICATOR   */
extern globus_object_t *
globus_object_construct_communicator (
);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_COMMUNICATOR   */
extern globus_object_t *
globus_object_initialize_communicator (
    globus_object_t * object
);


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_SOCKET_DEFINITION;

#define GLOBUS_OBJECT_TYPE_SOCKET \
        (&GLOBUS_OBJECT_TYPE_SOCKET_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_SOCKET   */
extern globus_object_t *
globus_object_construct_socket (
);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_SOCKET   */
extern globus_object_t *
globus_object_initialize_socket (
    globus_object_t * object
);


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_TASK_DEFINITION;

#define GLOBUS_OBJECT_TYPE_TASK \
        (&GLOBUS_OBJECT_TYPE_TASK_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_TASK   */
extern globus_object_t *
globus_object_construct_task (
    globus_object_t * task_request);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_TASK   */
extern globus_object_t *
globus_object_initialize_task (
    globus_object_t * object,
    globus_object_t * task_request);

/* return the task_request instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_TASK   */
extern globus_object_t *
globus_object_task_get_task_request (globus_object_t * object)
;

/* set the task_request instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_TASK   */
extern void
globus_object_task_set_task_request (
    globus_object_t * object,
    globus_object_t * value)
;


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_PROCESS_DEFINITION;

#define GLOBUS_OBJECT_TYPE_PROCESS \
        (&GLOBUS_OBJECT_TYPE_PROCESS_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_PROCESS   */
extern globus_object_t *
globus_object_construct_process (
    globus_object_t * task_request,
    globus_object_t * process_computer,
    long process_pid);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_PROCESS   */
extern globus_object_t *
globus_object_initialize_process (
    globus_object_t * object,
    globus_object_t * task_request,
    globus_object_t * process_computer,
    long process_pid);

/* return the process_computer instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_PROCESS   */
extern globus_object_t *
globus_object_process_get_process_computer (globus_object_t * object)
;

/* set the process_computer instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_PROCESS   */
extern void
globus_object_process_set_process_computer (
    globus_object_t * object,
    globus_object_t * value)
;

/* return the process_pid instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_PROCESS   */
extern long
globus_object_process_get_process_pid (globus_object_t * object)
;

/* set the process_pid instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_PROCESS   */
extern void
globus_object_process_set_process_pid (
    globus_object_t * object,
    long value)
;


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_GRAMJOB_DEFINITION;

#define GLOBUS_OBJECT_TYPE_GRAMJOB \
        (&GLOBUS_OBJECT_TYPE_GRAMJOB_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_GRAMJOB   */
extern globus_object_t *
globus_object_construct_gramjob (
    globus_object_t * task_request,
    globus_object_t * gramjob_gram_resource,
    char * gramjob_contact);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_GRAMJOB   */
extern globus_object_t *
globus_object_initialize_gramjob (
    globus_object_t * object,
    globus_object_t * task_request,
    globus_object_t * gramjob_gram_resource,
    char * gramjob_contact);

/* return the gramjob_gram_resource instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_GRAMJOB   */
extern globus_object_t *
globus_object_gramjob_get_gramjob_gram_resource (globus_object_t * object)
;

/* set the gramjob_gram_resource instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_GRAMJOB   */
extern void
globus_object_gramjob_set_gramjob_gram_resource (
    globus_object_t * object,
    globus_object_t * value)
;

/* return the gramjob_contact instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_GRAMJOB   */
extern char *
globus_object_gramjob_get_gramjob_contact (globus_object_t * object)
;

/* set the gramjob_contact instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_GRAMJOB   */
extern void
globus_object_gramjob_set_gramjob_contact (
    globus_object_t * object,
    char * value)
;


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_OPERATION_DEFINITION;

#define GLOBUS_OBJECT_TYPE_OPERATION \
        (&GLOBUS_OBJECT_TYPE_OPERATION_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_OPERATION   */
extern globus_object_t *
globus_object_construct_operation (
    globus_object_t * operation_identity,
    globus_object_t * operation_computer);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_OPERATION   */
extern globus_object_t *
globus_object_initialize_operation (
    globus_object_t * object,
    globus_object_t * operation_identity,
    globus_object_t * operation_computer);

/* return the operation_identity instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_OPERATION   */
extern globus_object_t *
globus_object_operation_get_operation_identity (globus_object_t * object)
;

/* set the operation_identity instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_OPERATION   */
extern void
globus_object_operation_set_operation_identity (
    globus_object_t * object,
    globus_object_t * value)
;

/* return the operation_computer instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_OPERATION   */
extern globus_object_t *
globus_object_operation_get_operation_computer (globus_object_t * object)
;

/* set the operation_computer instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_OPERATION   */
extern void
globus_object_operation_set_operation_computer (
    globus_object_t * object,
    globus_object_t * value)
;


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_READ_DEFINITION;

#define GLOBUS_OBJECT_TYPE_READ \
        (&GLOBUS_OBJECT_TYPE_READ_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_READ   */
extern globus_object_t *
globus_object_construct_read (
    globus_object_t * operation_identity,
    globus_object_t * operation_computer,
    globus_object_t * read_resource,
    long read_offset,
    long read_size);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_READ   */
extern globus_object_t *
globus_object_initialize_read (
    globus_object_t * object,
    globus_object_t * operation_identity,
    globus_object_t * operation_computer,
    globus_object_t * read_resource,
    long read_offset,
    long read_size);

/* return the read_resource instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_READ   */
extern globus_object_t *
globus_object_read_get_read_resource (globus_object_t * object)
;

/* set the read_resource instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_READ   */
extern void
globus_object_read_set_read_resource (
    globus_object_t * object,
    globus_object_t * value)
;

/* return the read_offset instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_READ   */
extern long
globus_object_read_get_read_offset (globus_object_t * object)
;

/* set the read_offset instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_READ   */
extern void
globus_object_read_set_read_offset (
    globus_object_t * object,
    long value)
;

/* return the read_size instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_READ   */
extern long
globus_object_read_get_read_size (globus_object_t * object)
;

/* set the read_size instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_READ   */
extern void
globus_object_read_set_read_size (
    globus_object_t * object,
    long value)
;


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_WRITE_DEFINITION;

#define GLOBUS_OBJECT_TYPE_WRITE \
        (&GLOBUS_OBJECT_TYPE_WRITE_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_WRITE   */
extern globus_object_t *
globus_object_construct_write (
    globus_object_t * operation_identity,
    globus_object_t * operation_computer,
    globus_object_t * write_resource,
    long write_offset,
    long write_size);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_WRITE   */
extern globus_object_t *
globus_object_initialize_write (
    globus_object_t * object,
    globus_object_t * operation_identity,
    globus_object_t * operation_computer,
    globus_object_t * write_resource,
    long write_offset,
    long write_size);

/* return the write_resource instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_WRITE   */
extern globus_object_t *
globus_object_write_get_write_resource (globus_object_t * object)
;

/* set the write_resource instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_WRITE   */
extern void
globus_object_write_set_write_resource (
    globus_object_t * object,
    globus_object_t * value)
;

/* return the write_offset instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_WRITE   */
extern long
globus_object_write_get_write_offset (globus_object_t * object)
;

/* set the write_offset instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_WRITE   */
extern void
globus_object_write_set_write_offset (
    globus_object_t * object,
    long value)
;

/* return the write_size instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_WRITE   */
extern long
globus_object_write_get_write_size (globus_object_t * object)
;

/* set the write_size instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_WRITE   */
extern void
globus_object_write_set_write_size (
    globus_object_t * object,
    long value)
;


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_APPEND_DEFINITION;

#define GLOBUS_OBJECT_TYPE_APPEND \
        (&GLOBUS_OBJECT_TYPE_APPEND_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_APPEND   */
extern globus_object_t *
globus_object_construct_append (
    globus_object_t * operation_identity,
    globus_object_t * operation_computer,
    globus_object_t * write_resource,
    long write_offset,
    long write_size);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_APPEND   */
extern globus_object_t *
globus_object_initialize_append (
    globus_object_t * object,
    globus_object_t * operation_identity,
    globus_object_t * operation_computer,
    globus_object_t * write_resource,
    long write_offset,
    long write_size);


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_EXECUTE_DEFINITION;

#define GLOBUS_OBJECT_TYPE_EXECUTE \
        (&GLOBUS_OBJECT_TYPE_EXECUTE_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_EXECUTE   */
extern globus_object_t *
globus_object_construct_execute (
    globus_object_t * operation_identity,
    globus_object_t * operation_computer,
    globus_object_t * execute_program);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_EXECUTE   */
extern globus_object_t *
globus_object_initialize_execute (
    globus_object_t * object,
    globus_object_t * operation_identity,
    globus_object_t * operation_computer,
    globus_object_t * execute_program);

/* return the execute_program instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_EXECUTE   */
extern globus_object_t *
globus_object_execute_get_execute_program (globus_object_t * object)
;

/* set the execute_program instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_EXECUTE   */
extern void
globus_object_execute_set_execute_program (
    globus_object_t * object,
    globus_object_t * value)
;


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_FORK_DEFINITION;

#define GLOBUS_OBJECT_TYPE_FORK \
        (&GLOBUS_OBJECT_TYPE_FORK_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_FORK   */
extern globus_object_t *
globus_object_construct_fork (
    globus_object_t * operation_identity,
    globus_object_t * operation_computer,
    globus_object_t * execute_program,
    globus_object_t * fork_parent);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_FORK   */
extern globus_object_t *
globus_object_initialize_fork (
    globus_object_t * object,
    globus_object_t * operation_identity,
    globus_object_t * operation_computer,
    globus_object_t * execute_program,
    globus_object_t * fork_parent);

/* return the fork_parent instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_FORK   */
extern globus_object_t *
globus_object_fork_get_fork_parent (globus_object_t * object)
;

/* set the fork_parent instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_FORK   */
extern void
globus_object_fork_set_fork_parent (
    globus_object_t * object,
    globus_object_t * value)
;


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_SYS_EXEC_DEFINITION;

#define GLOBUS_OBJECT_TYPE_SYS_EXEC \
        (&GLOBUS_OBJECT_TYPE_SYS_EXEC_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_SYS_EXEC   */
extern globus_object_t *
globus_object_construct_sys_exec (
    globus_object_t * operation_identity,
    globus_object_t * operation_computer,
    globus_object_t * execute_program,
    globus_list_t * sys_exec_arguments);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_SYS_EXEC   */
extern globus_object_t *
globus_object_initialize_sys_exec (
    globus_object_t * object,
    globus_object_t * operation_identity,
    globus_object_t * operation_computer,
    globus_object_t * execute_program,
    globus_list_t * sys_exec_arguments);

/* return the sys_exec_arguments instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_SYS_EXEC   */
extern globus_list_t *
globus_object_sys_exec_get_sys_exec_arguments (globus_object_t * object)
;

/* set the sys_exec_arguments instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_SYS_EXEC   */
extern void
globus_object_sys_exec_set_sys_exec_arguments (
    globus_object_t * object,
    globus_list_t * value)
;


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_SYS_EXECLE_DEFINITION;

#define GLOBUS_OBJECT_TYPE_SYS_EXECLE \
        (&GLOBUS_OBJECT_TYPE_SYS_EXECLE_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_SYS_EXECLE   */
extern globus_object_t *
globus_object_construct_sys_execle (
    globus_object_t * operation_identity,
    globus_object_t * operation_computer,
    globus_object_t * execute_program,
    globus_list_t * sys_exec_arguments,
    globus_list_t * sys_execle_environment);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_SYS_EXECLE   */
extern globus_object_t *
globus_object_initialize_sys_execle (
    globus_object_t * object,
    globus_object_t * operation_identity,
    globus_object_t * operation_computer,
    globus_object_t * execute_program,
    globus_list_t * sys_exec_arguments,
    globus_list_t * sys_execle_environment);

/* return the sys_execle_environment instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_SYS_EXECLE   */
extern globus_list_t *
globus_object_sys_execle_get_sys_execle_environment (globus_object_t * object)
;

/* set the sys_execle_environment instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_SYS_EXECLE   */
extern void
globus_object_sys_execle_set_sys_execle_environment (
    globus_object_t * object,
    globus_list_t * value)
;


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_GRAM_REQUEST_DEFINITION;

#define GLOBUS_OBJECT_TYPE_GRAM_REQUEST \
        (&GLOBUS_OBJECT_TYPE_GRAM_REQUEST_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_GRAM_REQUEST   */
extern globus_object_t *
globus_object_construct_gram_request (
    globus_object_t * operation_identity,
    globus_object_t * operation_computer,
    globus_object_t * execute_program,
    globus_object_t * gram_request_resource);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_GRAM_REQUEST   */
extern globus_object_t *
globus_object_initialize_gram_request (
    globus_object_t * object,
    globus_object_t * operation_identity,
    globus_object_t * operation_computer,
    globus_object_t * execute_program,
    globus_object_t * gram_request_resource);

/* return the gram_request_resource instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_GRAM_REQUEST   */
extern globus_object_t *
globus_object_gram_request_get_gram_request_resource (globus_object_t * object)
;

/* set the gram_request_resource instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_GRAM_REQUEST   */
extern void
globus_object_gram_request_set_gram_request_resource (
    globus_object_t * object,
    globus_object_t * value)
;


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_OPEN_CREATE_DEFINITION;

#define GLOBUS_OBJECT_TYPE_OPEN_CREATE \
        (&GLOBUS_OBJECT_TYPE_OPEN_CREATE_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_OPEN_CREATE   */
extern globus_object_t *
globus_object_construct_open_create (
    globus_object_t * operation_identity,
    globus_object_t * operation_computer,
    globus_object_t * open_create_resource);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_OPEN_CREATE   */
extern globus_object_t *
globus_object_initialize_open_create (
    globus_object_t * object,
    globus_object_t * operation_identity,
    globus_object_t * operation_computer,
    globus_object_t * open_create_resource);

/* return the open_create_resource instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_OPEN_CREATE   */
extern globus_object_t *
globus_object_open_create_get_open_create_resource (globus_object_t * object)
;

/* set the open_create_resource instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_OPEN_CREATE   */
extern void
globus_object_open_create_set_open_create_resource (
    globus_object_t * object,
    globus_object_t * value)
;


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_OPEN_DEFINITION;

#define GLOBUS_OBJECT_TYPE_OPEN \
        (&GLOBUS_OBJECT_TYPE_OPEN_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_OPEN   */
extern globus_object_t *
globus_object_construct_open (
    globus_object_t * operation_identity,
    globus_object_t * operation_computer,
    globus_object_t * open_create_resource);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_OPEN   */
extern globus_object_t *
globus_object_initialize_open (
    globus_object_t * object,
    globus_object_t * operation_identity,
    globus_object_t * operation_computer,
    globus_object_t * open_create_resource);


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_CREATE_DEFINITION;

#define GLOBUS_OBJECT_TYPE_CREATE \
        (&GLOBUS_OBJECT_TYPE_CREATE_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_CREATE   */
extern globus_object_t *
globus_object_construct_create (
    globus_object_t * operation_identity,
    globus_object_t * operation_computer,
    globus_object_t * open_create_resource,
    globus_list_t * create_mode);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_CREATE   */
extern globus_object_t *
globus_object_initialize_create (
    globus_object_t * object,
    globus_object_t * operation_identity,
    globus_object_t * operation_computer,
    globus_object_t * open_create_resource,
    globus_list_t * create_mode);

/* return the create_mode instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_CREATE   */
extern globus_list_t *
globus_object_create_get_create_mode (globus_object_t * object)
;

/* set the create_mode instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_CREATE   */
extern void
globus_object_create_set_create_mode (
    globus_object_t * object,
    globus_list_t * value)
;


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_CLOSE_DEFINITION;

#define GLOBUS_OBJECT_TYPE_CLOSE \
        (&GLOBUS_OBJECT_TYPE_CLOSE_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_CLOSE   */
extern globus_object_t *
globus_object_construct_close (
    globus_object_t * operation_identity,
    globus_object_t * operation_computer,
    globus_object_t * close_resource);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_CLOSE   */
extern globus_object_t *
globus_object_initialize_close (
    globus_object_t * object,
    globus_object_t * operation_identity,
    globus_object_t * operation_computer,
    globus_object_t * close_resource);

/* return the close_resource instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_CLOSE   */
extern globus_object_t *
globus_object_close_get_close_resource (globus_object_t * object)
;

/* set the close_resource instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_CLOSE   */
extern void
globus_object_close_set_close_resource (
    globus_object_t * object,
    globus_object_t * value)
;


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_USERDATA_DEFINITION;

#define GLOBUS_OBJECT_TYPE_USERDATA \
        (&GLOBUS_OBJECT_TYPE_USERDATA_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_USERDATA   */
extern globus_object_t *
globus_object_construct_userdata (
);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_USERDATA   */
extern globus_object_t *
globus_object_initialize_userdata (
    globus_object_t * object
);


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_RSL_DEFINITION;

#define GLOBUS_OBJECT_TYPE_RSL \
        (&GLOBUS_OBJECT_TYPE_RSL_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_RSL   */
extern globus_object_t *
globus_object_construct_rsl (
    char * rsl_string,
    void * rsl_globus_rsl);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_RSL   */
extern globus_object_t *
globus_object_initialize_rsl (
    globus_object_t * object,
    char * rsl_string,
    void * rsl_globus_rsl);

/* return the rsl_string instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_RSL   */
extern char *
globus_object_rsl_get_rsl_string (globus_object_t * object)
;

/* set the rsl_string instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_RSL   */
extern void
globus_object_rsl_set_rsl_string (
    globus_object_t * object,
    char * value)
;

/* return the rsl_globus_rsl instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_RSL   */
extern void *
globus_object_rsl_get_rsl_globus_rsl (globus_object_t * object)
;

/* set the rsl_globus_rsl instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_RSL   */
extern void
globus_object_rsl_set_rsl_globus_rsl (
    globus_object_t * object,
    void * value)
;


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_IDENTITY_DEFINITION;

#define GLOBUS_OBJECT_TYPE_IDENTITY \
        (&GLOBUS_OBJECT_TYPE_IDENTITY_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_IDENTITY   */
extern globus_object_t *
globus_object_construct_identity (
);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_IDENTITY   */
extern globus_object_t *
globus_object_initialize_identity (
    globus_object_t * object
);


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_LOCAL_IDENTITY_DEFINITION;

#define GLOBUS_OBJECT_TYPE_LOCAL_IDENTITY \
        (&GLOBUS_OBJECT_TYPE_LOCAL_IDENTITY_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_LOCAL_IDENTITY   */
extern globus_object_t *
globus_object_construct_local_identity (
    globus_object_t * local_identity_computer,
    char * local_identity_username);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_LOCAL_IDENTITY   */
extern globus_object_t *
globus_object_initialize_local_identity (
    globus_object_t * object,
    globus_object_t * local_identity_computer,
    char * local_identity_username);

/* return the local_identity_computer instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_LOCAL_IDENTITY   */
extern globus_object_t *
globus_object_local_identity_get_local_identity_computer (globus_object_t * object)
;

/* set the local_identity_computer instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_LOCAL_IDENTITY   */
extern void
globus_object_local_identity_set_local_identity_computer (
    globus_object_t * object,
    globus_object_t * value)
;

/* return the local_identity_username instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_LOCAL_IDENTITY   */
extern char *
globus_object_local_identity_get_local_identity_username (globus_object_t * object)
;

/* set the local_identity_username instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_LOCAL_IDENTITY   */
extern void
globus_object_local_identity_set_local_identity_username (
    globus_object_t * object,
    char * value)
;


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_GRID_IDENTITY_DEFINITION;

#define GLOBUS_OBJECT_TYPE_GRID_IDENTITY \
        (&GLOBUS_OBJECT_TYPE_GRID_IDENTITY_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_GRID_IDENTITY   */
extern globus_object_t *
globus_object_construct_grid_identity (
    char * grid_identity_subject);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_GRID_IDENTITY   */
extern globus_object_t *
globus_object_initialize_grid_identity (
    globus_object_t * object,
    char * grid_identity_subject);

/* return the grid_identity_subject instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_GRID_IDENTITY   */
extern char *
globus_object_grid_identity_get_grid_identity_subject (globus_object_t * object)
;

/* set the grid_identity_subject instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_GRID_IDENTITY   */
extern void
globus_object_grid_identity_set_grid_identity_subject (
    globus_object_t * object,
    char * value)
;


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_KERBEROS_IDENTITY_DEFINITION;

#define GLOBUS_OBJECT_TYPE_KERBEROS_IDENTITY \
        (&GLOBUS_OBJECT_TYPE_KERBEROS_IDENTITY_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_KERBEROS_IDENTITY   */
extern globus_object_t *
globus_object_construct_kerberos_identity (
    char * kerberos_identity_principal);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_KERBEROS_IDENTITY   */
extern globus_object_t *
globus_object_initialize_kerberos_identity (
    globus_object_t * object,
    char * kerberos_identity_principal);

/* return the kerberos_identity_principal instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_KERBEROS_IDENTITY   */
extern char *
globus_object_kerberos_identity_get_kerberos_identity_principal (globus_object_t * object)
;

/* set the kerberos_identity_principal instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_KERBEROS_IDENTITY   */
extern void
globus_object_kerberos_identity_set_kerberos_identity_principal (
    globus_object_t * object,
    char * value)
;


extern const globus_object_type_t
             GLOBUS_OBJECT_TYPE_TIME_DEFINITION;

#define GLOBUS_OBJECT_TYPE_TIME \
        (&GLOBUS_OBJECT_TYPE_TIME_DEFINITION)

/* allocate and initialize an object of type
 * GLOBUS_OBJECT_TYPE_TIME   */
extern globus_object_t *
globus_object_construct_time (
    time_t * time_time);

/* initialize and return an object of type
 * GLOBUS_OBJECT_TYPE_TIME   */
extern globus_object_t *
globus_object_initialize_time (
    globus_object_t * object,
    time_t * time_time);

/* return the time_time instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_TIME   */
extern time_t *
globus_object_time_get_time_time (globus_object_t * object)
;

/* set the time_time instance data of an object
 * derived from GLOBUS_OBJECT_TYPE_TIME   */
extern void
globus_object_time_set_time_time (
    globus_object_t * object,
    time_t * value)
;



EXTERN_C_END

#endif /* GLOBUS_OBJECT_HIERARCHY_H */


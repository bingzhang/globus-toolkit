
#ifndef GLOBUS_COMMON_LIST_H
#define GLOBUS_COMMON_LIST_H

#include "config.h"
#include "globus_common_types.h"
/********************************************************************
 *
 * This file defines the list_t type
 *
 *
 ********************************************************************/


EXTERN_C_BEGIN

typedef struct globus_list 
{
    void * volatile                        datum;
    struct globus_list * volatile          next;
    int                                    malloced;
} globus_list_t;

typedef int (*globus_list_pred_t) (void *datum, void *args);

typedef int (*globus_list_relation_t) (void *low_datum, void *high_datum,
				       void *relation_args);
int
globus_i_list_pre_activate(void);

extern int
globus_list_int_less (void * low_datum, void * high_datum,
		      void * ignored);

extern int 
globus_list_empty (globus_list_t * head);

extern void *
globus_list_first (globus_list_t * head);

extern globus_list_t *
globus_list_rest (globus_list_t * head);

extern globus_list_t **
globus_list_rest_ref (globus_list_t * head);

extern int 
globus_list_size (globus_list_t * head);

extern void *
globus_list_replace_first (globus_list_t * head, void *datum);

extern globus_list_t *
globus_list_search (globus_list_t * head, void * datum);

extern globus_list_t *
globus_list_search_pred (globus_list_t * head, 
			 globus_list_pred_t predicate,
			 void * pred_args);

extern globus_list_t *
globus_list_min (globus_list_t * head,
		 globus_list_relation_t relation,
		 void * relation_args);

extern globus_list_t *
globus_list_sort_destructive (globus_list_t * head,
			      globus_list_relation_t relation,
			      void *relation_args);

extern void
globus_list_halves_destructive (globus_list_t * head,
				globus_list_t * volatile * left_halfp,
				globus_list_t * volatile * right_halfp);

extern globus_list_t *
globus_list_sort_merge_destructive (globus_list_t *left,
				    globus_list_t *right,
				    globus_list_relation_t relation,
				    void * relation_args);

extern globus_list_t *
globus_list_sort (globus_list_t *head,
		  globus_list_relation_t relation,
		  void *relation_args);

extern int 
globus_list_insert (globus_list_t * volatile *headp, void *datum);

extern globus_list_t *
globus_list_cons (void * datum, globus_list_t *list);

extern globus_list_t *
globus_list_copy (globus_list_t *head);

extern void *
globus_list_remove (globus_list_t * volatile *headp, globus_list_t *entry);

extern void
globus_list_free (globus_list_t *head);

EXTERN_C_END

#endif /* GLOBUS_LIST_H */

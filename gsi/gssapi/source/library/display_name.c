#ifndef GLOBUS_DONT_DOCUMENT_INTERNAL
/**
 * @file display_name.c
 * @author Sam Lang, Sam Meder
 *
 * $RCSfile$
 * $Revision$
 * $Date$
 */
#endif

static char *rcsid = "$Id$";

#include "gssapi.h"
#include "globus_i_gsi_gss_utils.h"
#include "gssapi_openssl.h"
#include <string.h>

#define GSS_I_ANON_NAME "<anonymous>"

/**
 * @name Display Name
 * @ingroup globus_gsi_gssapi
 *
 * Produces a single line version of the internal x509 name
 *
 * @param minor_status 
 * @param input_name_P
 * @param output_name
 * @param output_name_type
 *
 * @return 
 */
OM_uint32 
GSS_CALLCONV 
gss_display_name(
    OM_uint32 *                         minor_status,
    const gss_name_t                    input_name_P,
    gss_buffer_t                        output_name,
    gss_OID *                           output_name_type)
{
    OM_uint32                           major_status;

    const gss_name_desc*                input_name = 
                                        (gss_name_desc*) input_name_P;
    static char *                       _function_name_ =
        "gss_display_name";

    GLOBUS_I_GSI_GSSAPI_DEBUG_ENTER;

    *minor_status = (OM_uint32) GLOBUS_SUCCESS;

    if (!(input_name) ||
        (!(input_name->x509n) &&
         !g_OID_equal(input_name->name_oid,
                      GSS_C_NT_ANONYMOUS)) ||
        !(output_name)) {
        major_status = GSS_S_FAILURE;
        GLOBUS_GSI_GSSAPI_ERROR_RESULT(
            minor_status, major_status, 
            GLOBUS_GSI_GSSAPI_ERROR_BAD_NAME,
            (NULL));
        goto exit;
    }

    if(!g_OID_equal(input_name->name_oid, GSS_C_NT_ANONYMOUS))
    {
        output_name->value = X509_NAME_oneline(input_name->x509n, NULL, 0);
        output_name->length = strlen(output_name->value);
    }
    else
    {
        output_name->value = (void *) strdup(GSS_I_ANON_NAME);
        output_name->length = strlen(GSS_I_ANON_NAME);
    }
  
    if (output_name_type)
    {
        *output_name_type = input_name->name_oid;
    }

    major_status = GSS_S_COMPLETE;

 exit:

    GLOBUS_I_GSI_GSSAPI_DEBUG_EXIT;
    return major_status;
} 
/* gss_export_name */
/* @} */

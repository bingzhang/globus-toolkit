#ifndef GLOBUS_DONT_DOCUMENT_INTERNAL
/**
 * @file export_sec_context.c
 * @author Sam Lang, Sam Meder
 *
 * $RCSfile$
 * $Revision$
 * $Date$
 */
#endif

static char *rcsid = "$Id$";

#include "gssapi_openssl.h"
#include "globus_i_gsi_gss_utils.h"
#include <string.h>

/**
 * @name Export Security Context
 * @ingroup globus_gsi_gssapi
 */
/* @{ */
/**
 * Saves the important info about the session, converts
 * it to a token, then deletes the context. 
 *
 * @param minor_status
 * @param context_handle_P
 * @param interprocess_token
 *
 * @return 
 *
 * For SSL handle We need to save:
 * version of this routine. 
 * cred_usage, i.e. are we accept or initiate
 * target/source or name
 * Session:  Protocol, cipher, and Master-Key
 * Client-Random
 * Server-Random
 * tmp.key_block: client and server Mac_secrets
 * write_sequence
 * read_sequence
 * write iv
 * read iv
 * 
 * see SSL 3.0 draft http://wp.netscape.com/eng/ssl3/index.html
 */
OM_uint32 
GSS_CALLCONV gss_export_sec_context(
    OM_uint32 *                         minor_status,
    gss_ctx_id_t *                      context_handle_P,
    gss_buffer_t                        interprocess_token) 
{
    OM_uint32                           major_status = GSS_S_COMPLETE;
    OM_uint32                           local_major_status;
    OM_uint32                           local_minor_status;
    globus_result_t                     local_result;
    gss_ctx_id_desc *                   context;
    int                                 peer_cert_count;
    SSL_SESSION *                       session = NULL;
    STACK_OF(X509) *                    cert_chain = NULL;
    BIO *                               bp = NULL;
    unsigned char                       int_buffer[4];
    OM_uint32                           cred_usage;
    int                                 index;
    int                                 length;
    unsigned char *                     context_serialized;
    static char *                       _function_name_ =
        "gss_export_sec_context";

    GLOBUS_I_GSI_GSSAPI_DEBUG_ENTER;

    *minor_status = (OM_uint32) GLOBUS_SUCCESS;

#ifdef WIN32
    major_status = GSS_S_UNAVAILABLE;
    GLOBUS_GSI_GSSAPI_ERROR_RESULT(
        minor_status,
        GLOBUS_GSI_GSSAPI_ERROR_UNSUPPORTED,
        ("This function does not currently support the "
         "Windows platform"));
    goto exit;
#endif

    context = *context_handle_P;

    if (context_handle_P == NULL || 
        context == (gss_ctx_id_t) GSS_C_NO_CONTEXT)
    {
        major_status = GSS_S_FAILURE;
        GLOBUS_GSI_GSSAPI_ERROR_RESULT(
            minor_status, major_status,
            GLOBUS_GSI_GSSAPI_ERROR_BAD_ARGUMENT,
            ("Invalid context handle passed to the function: %s",
             _function_name_));
        goto exit;
    }

    if (interprocess_token == NULL ||
        interprocess_token ==  GSS_C_NO_BUFFER)
    {
        major_status = GSS_S_FAILURE;
        GLOBUS_GSI_GSSAPI_ERROR_RESULT(
            minor_status, major_status,
            GLOBUS_GSI_GSSAPI_ERROR_BAD_ARGUMENT,
            ("Invalid interprocess token parameter passed to function: %s",
             _function_name_));
        goto exit;
    }

    /* Open mem bio for writing the session */
    bp = BIO_new(BIO_s_mem());
    if (bp == NULL)
    {
        major_status = GSS_S_FAILURE;
        GLOBUS_GSI_GSSAPI_ERROR_RESULT(
            minor_status, major_status,
            GLOBUS_GSI_GSSAPI_ERROR_IMPEXP_BIO_SSL,
            ("NULL bio for serializing SSL handle"));
        goto exit;
    }

    /* lock the context mutex */
    globus_mutex_lock(&context->mutex);

    interprocess_token->length = 0;

    /* version number */
    L2N(GLOBUS_I_GSI_GSSAPI_IMPL_VERSION, int_buffer);
    BIO_write(bp, (char *) int_buffer, 4);

    /* cred_usage */
    cred_usage = 
        context->locally_initiated ? GSS_C_INITIATE : GSS_C_ACCEPT;
    L2N(cred_usage, int_buffer);
    BIO_write(bp, (char *)int_buffer, 4);
	
    /* get session */
    session = SSL_get_session(context->gss_ssl);
    if (!session)
    {
        GLOBUS_GSI_GSSAPI_OPENSSL_ERROR_RESULT(
            minor_status,
            GLOBUS_GSI_GSSAPI_ERROR_IMPEXP_BIO_SSL,
            ("Couln't retrieve SSL session handle from SSL"));
        major_status = GSS_S_FAILURE;
        goto exit;
    }

    GLOBUS_I_GSI_GSSAPI_DEBUG_PRINT_OBJECT(3, SSL_SESSION, session);

    i2d_SSL_SESSION_bio(bp, session);

    local_result = globus_gsi_callback_get_cert_depth(context->callback_data,
                                                      &peer_cert_count);
    if(local_result != GLOBUS_SUCCESS)
    {
        GLOBUS_GSI_GSSAPI_ERROR_CHAIN_RESULT(
            minor_status, local_result,
            GLOBUS_GSI_GSSAPI_ERROR_WITH_CALLBACK_DATA);
        major_status = GSS_S_FAILURE;
        goto exit;
    }

    L2N(peer_cert_count, (char *)int_buffer);
    BIO_write(bp, (char *)int_buffer, 4);
    
    for(index = 0; index < peer_cert_count; ++index)
    {
        local_result = globus_gsi_callback_get_cert_chain(
            context->callback_data,
            &cert_chain);
        if(local_result != GLOBUS_SUCCESS)
        {
            GLOBUS_GSI_GSSAPI_ERROR_CHAIN_RESULT(
                minor_status, local_result,
                GLOBUS_GSI_GSSAPI_ERROR_WITH_CALLBACK_DATA);
            major_status = GSS_S_FAILURE;
            goto exit;
        }

        i2d_X509_bio(bp, sk_X509_value(cert_chain, index));
    }
    
    local_major_status = globus_i_gsi_gss_ssl_serialize(&local_minor_status,
                                                        context,
                                                        bp);
    if(GSS_ERROR(local_major_status))
    {
        GLOBUS_GSI_GSSAPI_ERROR_CHAIN_RESULT(
            minor_status,
            local_minor_status,
            GLOBUS_GSI_GSSAPI_ERROR_IMPEXP_BIO_SSL);
        major_status = local_major_status;
        goto exit;
    }
    
    /* now get it out of the BIO and call it a token */
    length = BIO_pending(bp);
    if (length <= 0)
    {
        GLOBUS_GSI_GSSAPI_OPENSSL_ERROR_RESULT(
            minor_status,
            GLOBUS_GSI_GSSAPI_ERROR_IMPEXP_BIO_SSL,
            ("Couldn't get data from BIO for serializing SSL handle"));
        major_status = GSS_S_FAILURE;
        goto exit;
    }

    context_serialized = (unsigned char *) globus_libc_malloc(length);

    if (!context_serialized)
    {
        GLOBUS_GSI_GSSAPI_MALLOC_ERROR(minor_status);
        major_status = GSS_S_NO_CONTEXT;
        goto exit;
    }
    
    BIO_read(bp, (char *)context_serialized, length);
    
    interprocess_token->length = length;
    interprocess_token->value = context_serialized;

    /* unlock the context mutex */
    globus_mutex_unlock(&context->mutex);
    
    /* Now delete the GSS context as per RFC */
    major_status = gss_delete_sec_context(&local_minor_status,
                                          context_handle_P,
                                          GSS_C_NO_BUFFER);
    if(GSS_ERROR(major_status))
    {
        GLOBUS_GSI_GSSAPI_ERROR_CHAIN_RESULT(
            minor_status, local_minor_status,
            GLOBUS_GSI_GSSAPI_ERROR_WITH_GSS_CONTEXT);
        goto exit;
    }
    
exit:
    
    if(bp)
    {
        BIO_free(bp);
    }

    GLOBUS_I_GSI_GSSAPI_DEBUG_EXIT;
    return major_status;
}
/* @} */

/*------------------------------------------------------------------------------
*
* Copyright (c) 2011-2018, EURid vzw. All rights reserved.
* The YADIFA TM software product is provided under the BSD 3-clause license:
* 
* Redistribution and use in source and binary forms, with or without 
* modification, are permitted provided that the following conditions
* are met:
*
*        * Redistributions of source code must retain the above copyright 
*          notice, this list of conditions and the following disclaimer.
*        * Redistributions in binary form must reproduce the above copyright 
*          notice, this list of conditions and the following disclaimer in the 
*          documentation and/or other materials provided with the distribution.
*        * Neither the name of EURid nor the names of its contributors may be 
*          used to endorse or promote products derived from this software 
*          without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
*------------------------------------------------------------------------------
*
*/

/** @defgroup yadifa
 *  @ingroup ###
 *  @brief 
 */

#define SERVER_C_
#define MODULE_MSG_HANDLE g_client_logger

#include <unistd.h>
#include <sys/time.h>

#include <dnscore/logger.h>
#include <dnscore/message.h>
#include <dnscore/tcp_io_stream.h>
#include <dnscore/ctrl-rfc.h>

#include <dnslg/dns.h>



#include "yadifa-config.h"
#include "yadifa.h"
#include "query-result.h"
#include "message-viewer-dig.h"

/*----------------------------------------------------------------------------*/
#pragma mark GLOBAL VARIABLES

logger_handle *g_client_logger;
extern config_main_settings_s       g_yadifa_main_settings;

/*----------------------------------------------------------------------------*/

#pragma mark STATIC PROTOTYPES

/*----------------------------------------------------------------------------*/
#pragma mark FUNCTIONS

/** @brief time_diff_in_msec (timeval_1 - timeval_2)
 *
 *  @param tv1 const struct timeval
 *  @param tv2 const struct timeval
 *  @retval timeval_1 - timeval_2 in msec
 */
static long
time_diff_in_msec(const struct timeval *tv1, const struct timeval *tv2)
{
//    if(tv1 == NULL || tv2 == NULL)
//    {
//      error_quit("One or both timeval are NULL");
//    }

    return( (tv1->tv_sec * 1000 + tv1->tv_usec / 1000) - (tv2->tv_sec * 1000 + tv2->tv_usec / 1000));
}

/** @brief time_now gives the time of the day now
 *
 *  @param tv struct timeval *
 *  @retval tv 
 *  @retrun OK or NOK
 */
static int
time_now(struct timeval *tv)
{
    if(tv == NULL)
    {
        return NOK;
    }

    if(-1 == gettimeofday(tv, NULL))
    {
        // error_msg("time now: %s\n", strerror(errno));

        return NOK;
    }

    return OK;
}





/** @brief yadifa_run main function for controlling yadifad
 *
 *  @param none
 *  @retrun ya_result
 */
ya_result
yadifa_run()
{
    ya_result                                              return_code = OK;

    /*    ------------------------------------------------------------    */





    message_data                                                       mesg;
    struct timeval                                          query_time_send;
    struct timeval                                      query_time_received;

    u8                                                          go_tcp = OK;

     /*    ------------------------------------------------------------    */

    /* give ID from config or randomized */
    u16 id                = dns_new_id();
    u16 qtype             = htons(g_yadifa_main_settings.qtype);
    u8 *qname             = g_yadifa_main_settings.qname;

#if 0 /* fix */
#else
    u16 question_mode     = 0;
#endif // if 0


    /* prepare root tld */
    char *root = ".";
    u8 root_fqdn[MAX_DOMAIN_LENGTH];
    cstr_to_dnsname(root_fqdn, root);



    switch(qtype)
    {
        case TYPE_NONE:
            osformatln(termerr, "expected a valid command");
            flusherr();

            return return_code;

        case TYPE_CTRL_ZONEFREEZE:
        case TYPE_CTRL_ZONEUNFREEZE:
        case TYPE_CTRL_ZONERELOAD:
        case TYPE_CTRL_ZONECFGRELOAD:
        {
            message_make_query(&mesg, id, root_fqdn, qtype, CLASS_CTRL);

            packet_writer pw;
            packet_writer_init(&pw, mesg.buffer, mesg.send_length, sizeof(mesg.buffer));

            packet_writer_add_record(&pw, root_fqdn, qtype, CLASS_CTRL, 0, qname, (u16)dnsname_len(qname));
            MESSAGE_SET_AN(mesg.buffer, htons(1));

            mesg.send_length = packet_writer_get_offset(&pw);

            break;
        }
        /* the same as zone freeze, but without extra information */
        case TYPE_CTRL_ZONEFREEZEALL:
        {
            message_make_query(&mesg, id, root_fqdn, TYPE_CTRL_ZONEFREEZE, CLASS_CTRL);

            break;
        }
        /* the same as zone freeze, but without extra information */
        case TYPE_CTRL_ZONEUNFREEZEALL:
        {
            message_make_query(&mesg, id, root_fqdn, TYPE_CTRL_ZONEUNFREEZE, CLASS_CTRL);

            break;
        }
        /* the same as zone unfreeze, but without extra information */
        case TYPE_CTRL_ZONECFGRELOADALL:              
        {
            message_make_query(&mesg, id, root_fqdn, TYPE_CTRL_ZONECFGRELOAD, CLASS_CTRL);

            break;
        }

        case TYPE_CTRL_SRVLOGLEVEL:
        {
            /* 1. create rdata part for the 'added record'
                  - 1 byte (0 or 1) from --clean command line parameter
                  - qname
            */
            u8 buffer[256]; // max domain name length + 1 byte for clean value

            buffer[0]      = MIN(g_yadifa_main_settings.log_level, MSG_ALL);
            u16 buffer_len = 1;

            /* 2. make message */
            message_make_query(&mesg, id, root_fqdn, qtype, CLASS_CTRL);

            /* 3. modify message, add an extra resource record */
            packet_writer pw;
            packet_writer_init(&pw, mesg.buffer, mesg.send_length, sizeof(mesg.buffer));

            packet_writer_add_record(&pw, root_fqdn, qtype, CLASS_CTRL, 0, buffer, buffer_len);

            MESSAGE_SET_AN(mesg.buffer, htons(1));

            mesg.send_length = packet_writer_get_offset(&pw);
            
            break;
        }

        /** @todo 20150219 gve -- still needs to check this on yadifad side */
        case TYPE_CTRL_ZONESYNC:
        {
            /* 1. create rdata part for the 'added record'
                  - 1 byte (0 or 1) from --clean command line parameter
                  - qname
            */
            u8 buffer[256]; // max domain name length + 1 byte for clean value

            buffer[0]      = (u8)g_yadifa_main_settings.clean;
            u16 buffer_len = 1;

            dnsname_copy(&buffer[1], qname);
            buffer_len += (u16)dnsname_len(qname);

            /* 2. make message */
            message_make_query(&mesg, id, root_fqdn, qtype, CLASS_CTRL);

            /* 3. modify message, add an extra resource record */
            packet_writer pw;
            packet_writer_init(&pw, mesg.buffer, mesg.send_length, sizeof(mesg.buffer));

            packet_writer_add_record(&pw, root_fqdn, qtype, CLASS_CTRL, 0, buffer, buffer_len);

            MESSAGE_SET_AN(mesg.buffer, htons(1));

            mesg.send_length = packet_writer_get_offset(&pw);

            break;
        }
        case TYPE_CTRL_SRVQUERYLOG:
        {
            /* 1. make message */
            message_make_query(&mesg, id, root_fqdn, qtype, CLASS_CTRL);

            /* 2. modify message, add an extra resource record */
            packet_writer pw;
            packet_writer_init(&pw, mesg.buffer, mesg.send_length, sizeof(mesg.buffer));

            if(g_yadifa_main_settings.enable) /* from command line parameter */
            {
                u8 c = '1';
                packet_writer_add_record(&pw, root_fqdn, qtype, CLASS_CTRL, 0, &c, 1);
            }
            else
            {
                u8 c = '0';
                packet_writer_add_record(&pw, root_fqdn, qtype, CLASS_CTRL, 0, &c, 1);
            }
            MESSAGE_SET_AN(mesg.buffer, htons(1));

            mesg.send_length = packet_writer_get_offset(&pw);

            break;
        }
        // case TYPE_CTRL_LOGREOPEN:
        // case TYPE_CTRL_SHUTDOWN
        // case TYPE_CTRL_SRVCFGRELOAD  (-t cfgreload)
        default:
        {
            message_make_query(&mesg, id, root_fqdn, qtype, CLASS_CTRL);

            break;
        }
    }


    MESSAGE_SET_OP(mesg.buffer, OPCODE_CTRL);
     
    /**  TSIG check and returns if not good
     *  @note TSIG is always needed for the controller
     */ 
    if(FAIL(return_code = message_sign_query_by_name(&mesg, g_yadifa_main_settings.tsig_key_name)))
    {
        /** @todo 20150217 gve -- needs to send back a good return value */
        if(return_code == TSIG_BADKEY)
        {
            osformatln(termerr, "bad tsig key: %r", return_code);
            flusherr();
        }
        else if(return_code == TSIG_SIZE_LIMIT_ERROR)
        {
            osformatln(termerr, "bad tsig key size: %r", return_code); /** @todo 20140630 gve -- better logging */
            flusherr();
        }

        return return_code;
    }
    
    /* fix the tcp length */
    message_update_tcp_length(&mesg);

    /* set timer before send */
    time_now(&query_time_send);

    u8 connect_timeout = 3;
    if(FAIL(return_code = message_query_tcp_with_timeout(&mesg, g_yadifa_main_settings.server, connect_timeout)))
    {
        osformatln(termerr, "wrong %{hostaddr}: %r", g_yadifa_main_settings.server, return_code); /** @todo 20140630 gve -- better logging */
        flusherr();

        return return_code;
    }

    /* stop timer after received */
    time_now(&query_time_received);


#if 0 /* fix */
#else
    u16 protocol         = 0;
#endif // if 0

    return_code = query_result_check(id, protocol, question_mode, &mesg, &go_tcp);

    /* show the result if verbose */
    if(g_yadifa_main_settings.verbose)
    {
        /// @todo 20150715 gve -- needs to be modified for view_with_mode
        message_viewer mv;
        message_viewer_dig_init(&mv, termout, 0);

        if(FAIL(return_code = query_result_view(&mv, &mesg, time_diff_in_msec(&query_time_received, &query_time_send), 0)))
        {
            return return_code;
        }
    }

    if(ISOK(return_code))
    {
        osformatln(termout, "%s", get_rcode(MESSAGE_RCODE(mesg.buffer)));
    }
    else
    {
        osformatln(termerr, "error: %r", return_code);
    }

    return return_code;
}


/*----------------------------------------------------------------------------*/


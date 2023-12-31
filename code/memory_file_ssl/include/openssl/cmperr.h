/*/*******************************************************************************
**                                                                            **
**                     Jiedi(China nanjing)Ltd.                               **
**	               创建：丁宋涛 夏曹俊，此代码可用作为学习参考                **
*******************************************************************************/

/*****************************FILE INFOMATION***********************************
**
** Project       :c++实战区块链核心密码学-基于openssl
** Contact       : xiacaojun@qq.com
**  博客   : http://blog.csdn.net/jiedichina
**	视频课程 : 网易云课堂	http://study.163.com/u/xiacaojun		
			   腾讯课堂		https://jiedi.ke.qq.com/				
			   csdn学院               http://edu.csdn.net/lecturer/lecturer_detail?lecturer_id=961	
**             51cto学院              http://edu.51cto.com/lecturer/index/user_id-12016059.html	
** 			   老夏课堂		http://www.laoxiaketang.com 
**              课程代码和OpenSSL库下载地址           http://OpenSSL.VIP   
**  openssl  公开课 课程群 ：296249312加入群下载代码和学员交流
**                           微信公众号  : jiedi2007
**		头条号	 : 夏曹俊
**
*****************************************************************************
//！！！！！！！！！openssl  公开课 课程  QQ群：296249312下载代码和学员交流*/

/*
 * Generated by util/mkerr.pl DO NOT EDIT
 * Copyright 1995-2020 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef OPENSSL_CMPERR_H
# define OPENSSL_CMPERR_H

# include <openssl/opensslconf.h>
# include <openssl/symhacks.h>


# include <openssl/opensslconf.h>

# ifndef OPENSSL_NO_CMP

#  ifdef  __cplusplus
extern "C"
#  endif
int ERR_load_CMP_strings(void);

/*
 * CMP function codes.
 */
# ifndef OPENSSL_NO_DEPRECATED_3_0
# endif

/*
 * CMP reason codes.
 */
#  define CMP_R_ALGORITHM_NOT_SUPPORTED                    139
#  define CMP_R_BAD_CHECKAFTER_IN_POLLREP                  167
#  define CMP_R_BAD_REQUEST_ID                             108
#  define CMP_R_CERTHASH_UNMATCHED                         156
#  define CMP_R_CERTID_NOT_FOUND                           109
#  define CMP_R_CERTIFICATE_NOT_ACCEPTED                   169
#  define CMP_R_CERTIFICATE_NOT_FOUND                      112
#  define CMP_R_CERTREQMSG_NOT_FOUND                       157
#  define CMP_R_CERTRESPONSE_NOT_FOUND                     113
#  define CMP_R_CERT_AND_KEY_DO_NOT_MATCH                  114
#  define CMP_R_CHECKAFTER_OUT_OF_RANGE                    181
#  define CMP_R_CHECKING_PBM_NO_SECRET_AVAILABLE           166
#  define CMP_R_ENCOUNTERED_KEYUPDATEWARNING               176
#  define CMP_R_ENCOUNTERED_WAITING                        162
#  define CMP_R_ERROR_CALCULATING_PROTECTION               115
#  define CMP_R_ERROR_CREATING_CERTCONF                    116
#  define CMP_R_ERROR_CREATING_CERTREP                     117
#  define CMP_R_ERROR_CREATING_CR                          163
#  define CMP_R_ERROR_CREATING_ERROR                       118
#  define CMP_R_ERROR_CREATING_GENM                        119
#  define CMP_R_ERROR_CREATING_GENP                        120
#  define CMP_R_ERROR_CREATING_IR                          164
#  define CMP_R_ERROR_CREATING_KUR                         165
#  define CMP_R_ERROR_CREATING_P10CR                       121
#  define CMP_R_ERROR_CREATING_PKICONF                     122
#  define CMP_R_ERROR_CREATING_POLLREP                     123
#  define CMP_R_ERROR_CREATING_POLLREQ                     124
#  define CMP_R_ERROR_CREATING_RP                          125
#  define CMP_R_ERROR_CREATING_RR                          126
#  define CMP_R_ERROR_PARSING_PKISTATUS                    107
#  define CMP_R_ERROR_PROCESSING_MESSAGE                   158
#  define CMP_R_ERROR_PROTECTING_MESSAGE                   127
#  define CMP_R_ERROR_SETTING_CERTHASH                     128
#  define CMP_R_ERROR_UNEXPECTED_CERTCONF                  160
#  define CMP_R_ERROR_VALIDATING_PROTECTION                140
#  define CMP_R_FAILED_EXTRACTING_PUBKEY                   141
#  define CMP_R_FAILURE_OBTAINING_RANDOM                   110
#  define CMP_R_FAIL_INFO_OUT_OF_RANGE                     129
#  define CMP_R_INVALID_ARGS                               100
#  define CMP_R_MISSING_KEY_INPUT_FOR_CREATING_PROTECTION  130
#  define CMP_R_MISSING_KEY_USAGE_DIGITALSIGNATURE         142
#  define CMP_R_MISSING_PRIVATE_KEY                        131
#  define CMP_R_MISSING_PROTECTION                         143
#  define CMP_R_MISSING_REFERENCE_CERT                     168
#  define CMP_R_MISSING_SENDER_IDENTIFICATION              111
#  define CMP_R_MISSING_TRUST_STORE                        144
#  define CMP_R_MULTIPLE_REQUESTS_NOT_SUPPORTED            161
#  define CMP_R_MULTIPLE_RESPONSES_NOT_SUPPORTED           170
#  define CMP_R_MULTIPLE_SAN_SOURCES                       102
#  define CMP_R_NO_STDIO                                   194
#  define CMP_R_NO_SUITABLE_SENDER_CERT                    145
#  define CMP_R_NULL_ARGUMENT                              103
#  define CMP_R_PKIBODY_ERROR                              146
#  define CMP_R_PKISTATUSINFO_NOT_FOUND                    132
#  define CMP_R_POLLING_FAILED                             172
#  define CMP_R_POTENTIALLY_INVALID_CERTIFICATE            147
#  define CMP_R_RECEIVED_ERROR                             180
#  define CMP_R_RECIPNONCE_UNMATCHED                       148
#  define CMP_R_REQUEST_NOT_ACCEPTED                       149
#  define CMP_R_REQUEST_REJECTED_BY_SERVER                 182
#  define CMP_R_SENDER_GENERALNAME_TYPE_NOT_SUPPORTED      150
#  define CMP_R_SRVCERT_DOES_NOT_VALIDATE_MSG              151
#  define CMP_R_TOTAL_TIMEOUT                              184
#  define CMP_R_TRANSACTIONID_UNMATCHED                    152
#  define CMP_R_TRANSFER_ERROR                             159
#  define CMP_R_UNEXPECTED_PKIBODY                         133
#  define CMP_R_UNEXPECTED_PKISTATUS                       185
#  define CMP_R_UNEXPECTED_PVNO                            153
#  define CMP_R_UNKNOWN_ALGORITHM_ID                       134
#  define CMP_R_UNKNOWN_CERT_TYPE                          135
#  define CMP_R_UNKNOWN_PKISTATUS                          186
#  define CMP_R_UNSUPPORTED_ALGORITHM                      136
#  define CMP_R_UNSUPPORTED_KEY_TYPE                       137
#  define CMP_R_UNSUPPORTED_PROTECTION_ALG_DHBASEDMAC      154
#  define CMP_R_WRONG_ALGORITHM_OID                        138
#  define CMP_R_WRONG_CERTID_IN_RP                         187
#  define CMP_R_WRONG_PBM_VALUE                            155
#  define CMP_R_WRONG_RP_COMPONENT_COUNT                   188
#  define CMP_R_WRONG_SERIAL_IN_RP                         173

# endif
#endif

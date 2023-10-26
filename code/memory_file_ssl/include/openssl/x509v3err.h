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

#ifndef OPENSSL_X509V3ERR_H
# define OPENSSL_X509V3ERR_H
# pragma once

# include <openssl/opensslconf.h>
# include <openssl/symhacks.h>


# ifdef  __cplusplus
extern "C"
# endif
int ERR_load_X509V3_strings(void);

/*
 * X509V3 function codes.
 */
# ifndef OPENSSL_NO_DEPRECATED_3_0
#  define X509V3_F_A2I_GENERAL_NAME                        0
#  define X509V3_F_ADDR_VALIDATE_PATH_INTERNAL             0
#  define X509V3_F_ASIDENTIFIERCHOICE_CANONIZE             0
#  define X509V3_F_ASIDENTIFIERCHOICE_IS_CANONICAL         0
#  define X509V3_F_BIGNUM_TO_STRING                        0
#  define X509V3_F_COPY_EMAIL                              0
#  define X509V3_F_COPY_ISSUER                             0
#  define X509V3_F_DO_DIRNAME                              0
#  define X509V3_F_DO_EXT_I2D                              0
#  define X509V3_F_DO_EXT_NCONF                            0
#  define X509V3_F_GNAMES_FROM_SECTNAME                    0
#  define X509V3_F_I2R_ISSUER_SIGN_TOOL                    0
#  define X509V3_F_I2S_ASN1_ENUMERATED                     0
#  define X509V3_F_I2S_ASN1_IA5STRING                      0
#  define X509V3_F_I2S_ASN1_INTEGER                        0
#  define X509V3_F_I2S_ASN1_UTF8STRING                     0
#  define X509V3_F_I2V_AUTHORITY_INFO_ACCESS               0
#  define X509V3_F_LEVEL_ADD_NODE                          0
#  define X509V3_F_NOTICE_SECTION                          0
#  define X509V3_F_NREF_NOS                                0
#  define X509V3_F_POLICY_CACHE_CREATE                     0
#  define X509V3_F_POLICY_CACHE_NEW                        0
#  define X509V3_F_POLICY_DATA_NEW                         0
#  define X509V3_F_POLICY_SECTION                          0
#  define X509V3_F_PROCESS_PCI_VALUE                       0
#  define X509V3_F_R2I_CERTPOL                             0
#  define X509V3_F_R2I_PCI                                 0
#  define X509V3_F_S2I_ASN1_IA5STRING                      0
#  define X509V3_F_S2I_ASN1_INTEGER                        0
#  define X509V3_F_S2I_ASN1_OCTET_STRING                   0
#  define X509V3_F_S2I_ASN1_UTF8STRING                     0
#  define X509V3_F_S2I_SKEY_ID                             0
#  define X509V3_F_SET_DIST_POINT_NAME                     0
#  define X509V3_F_SXNET_ADD_ID_ASC                        0
#  define X509V3_F_SXNET_ADD_ID_INTEGER                    0
#  define X509V3_F_SXNET_ADD_ID_ULONG                      0
#  define X509V3_F_SXNET_GET_ID_ASC                        0
#  define X509V3_F_SXNET_GET_ID_ULONG                      0
#  define X509V3_F_TREE_INIT                               0
#  define X509V3_F_V2I_ASIDENTIFIERS                       0
#  define X509V3_F_V2I_ASN1_BIT_STRING                     0
#  define X509V3_F_V2I_AUTHORITY_INFO_ACCESS               0
#  define X509V3_F_V2I_AUTHORITY_KEYID                     0
#  define X509V3_F_V2I_BASIC_CONSTRAINTS                   0
#  define X509V3_F_V2I_CRLD                                0
#  define X509V3_F_V2I_EXTENDED_KEY_USAGE                  0
#  define X509V3_F_V2I_GENERAL_NAMES                       0
#  define X509V3_F_V2I_GENERAL_NAME_EX                     0
#  define X509V3_F_V2I_IDP                                 0
#  define X509V3_F_V2I_IPADDRBLOCKS                        0
#  define X509V3_F_V2I_ISSUER_ALT                          0
#  define X509V3_F_V2I_ISSUER_SIGN_TOOL                    0
#  define X509V3_F_V2I_NAME_CONSTRAINTS                    0
#  define X509V3_F_V2I_POLICY_CONSTRAINTS                  0
#  define X509V3_F_V2I_POLICY_MAPPINGS                     0
#  define X509V3_F_V2I_SUBJECT_ALT                         0
#  define X509V3_F_V2I_TLS_FEATURE                         0
#  define X509V3_F_V3_GENERIC_EXTENSION                    0
#  define X509V3_F_X509V3_ADD1_I2D                         0
#  define X509V3_F_X509V3_ADD_VALUE                        0
#  define X509V3_F_X509V3_EXT_ADD                          0
#  define X509V3_F_X509V3_EXT_ADD_ALIAS                    0
#  define X509V3_F_X509V3_EXT_I2D                          0
#  define X509V3_F_X509V3_EXT_NCONF                        0
#  define X509V3_F_X509V3_GET_SECTION                      0
#  define X509V3_F_X509V3_GET_STRING                       0
#  define X509V3_F_X509V3_GET_VALUE_BOOL                   0
#  define X509V3_F_X509V3_PARSE_LIST                       0
#  define X509V3_F_X509_PURPOSE_ADD                        0
#  define X509V3_F_X509_PURPOSE_SET                        0
# endif

/*
 * X509V3 reason codes.
 */
# define X509V3_R_BAD_IP_ADDRESS                          118
# define X509V3_R_BAD_OBJECT                              119
# define X509V3_R_BN_DEC2BN_ERROR                         100
# define X509V3_R_BN_TO_ASN1_INTEGER_ERROR                101
# define X509V3_R_DIRNAME_ERROR                           149
# define X509V3_R_DISTPOINT_ALREADY_SET                   160
# define X509V3_R_DUPLICATE_ZONE_ID                       133
# define X509V3_R_ERROR_CONVERTING_ZONE                   131
# define X509V3_R_ERROR_CREATING_EXTENSION                144
# define X509V3_R_ERROR_IN_EXTENSION                      128
# define X509V3_R_EXPECTED_A_SECTION_NAME                 137
# define X509V3_R_EXTENSION_EXISTS                        145
# define X509V3_R_EXTENSION_NAME_ERROR                    115
# define X509V3_R_EXTENSION_NOT_FOUND                     102
# define X509V3_R_EXTENSION_SETTING_NOT_SUPPORTED         103
# define X509V3_R_EXTENSION_VALUE_ERROR                   116
# define X509V3_R_ILLEGAL_EMPTY_EXTENSION                 151
# define X509V3_R_INCORRECT_POLICY_SYNTAX_TAG             152
# define X509V3_R_INVALID_ASNUMBER                        162
# define X509V3_R_INVALID_ASRANGE                         163
# define X509V3_R_INVALID_BOOLEAN_STRING                  104
# define X509V3_R_INVALID_EXTENSION_STRING                105
# define X509V3_R_INVALID_INHERITANCE                     165
# define X509V3_R_INVALID_IPADDRESS                       166
# define X509V3_R_INVALID_MULTIPLE_RDNS                   161
# define X509V3_R_INVALID_NAME                            106
# define X509V3_R_INVALID_NULL_ARGUMENT                   107
# define X509V3_R_INVALID_NULL_NAME                       108
# define X509V3_R_INVALID_NULL_VALUE                      109
# define X509V3_R_INVALID_NUMBER                          140
# define X509V3_R_INVALID_NUMBERS                         141
# define X509V3_R_INVALID_OBJECT_IDENTIFIER               110
# define X509V3_R_INVALID_OPTION                          138
# define X509V3_R_INVALID_POLICY_IDENTIFIER               134
# define X509V3_R_INVALID_PROXY_POLICY_SETTING            153
# define X509V3_R_INVALID_PURPOSE                         146
# define X509V3_R_INVALID_SAFI                            164
# define X509V3_R_INVALID_SECTION                         135
# define X509V3_R_INVALID_SYNTAX                          143
# define X509V3_R_ISSUER_DECODE_ERROR                     126
# define X509V3_R_MISSING_VALUE                           124
# define X509V3_R_NEED_ORGANIZATION_AND_NUMBERS           142
# define X509V3_R_NO_CONFIG_DATABASE                      136
# define X509V3_R_NO_ISSUER_CERTIFICATE                   121
# define X509V3_R_NO_ISSUER_DETAILS                       127
# define X509V3_R_NO_POLICY_IDENTIFIER                    139
# define X509V3_R_NO_PROXY_CERT_POLICY_LANGUAGE_DEFINED   154
# define X509V3_R_NO_PUBLIC_KEY                           114
# define X509V3_R_NO_SUBJECT_DETAILS                      125
# define X509V3_R_OPERATION_NOT_DEFINED                   148
# define X509V3_R_OTHERNAME_ERROR                         147
# define X509V3_R_POLICY_LANGUAGE_ALREADY_DEFINED         155
# define X509V3_R_POLICY_PATH_LENGTH                      156
# define X509V3_R_POLICY_PATH_LENGTH_ALREADY_DEFINED      157
# define X509V3_R_POLICY_WHEN_PROXY_LANGUAGE_REQUIRES_NO_POLICY 159
# define X509V3_R_SECTION_NOT_FOUND                       150
# define X509V3_R_UNABLE_TO_GET_ISSUER_DETAILS            122
# define X509V3_R_UNABLE_TO_GET_ISSUER_KEYID              123
# define X509V3_R_UNKNOWN_BIT_STRING_ARGUMENT             111
# define X509V3_R_UNKNOWN_EXTENSION                       129
# define X509V3_R_UNKNOWN_EXTENSION_NAME                  130
# define X509V3_R_UNKNOWN_OPTION                          120
# define X509V3_R_UNSUPPORTED_OPTION                      117
# define X509V3_R_UNSUPPORTED_TYPE                        167
# define X509V3_R_USER_TOO_LONG                           132

#endif

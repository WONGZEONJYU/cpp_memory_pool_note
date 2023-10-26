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

#ifndef OPENSSL_CRMFERR_H
# define OPENSSL_CRMFERR_H

# include <openssl/opensslconf.h>
# include <openssl/symhacks.h>


# include <openssl/opensslconf.h>

# ifndef OPENSSL_NO_CRMF

#  ifdef  __cplusplus
extern "C"
#  endif
int ERR_load_CRMF_strings(void);

/*
 * CRMF function codes.
 */
# ifndef OPENSSL_NO_DEPRECATED_3_0
#   define CRMF_F_CRMF_POPOSIGNINGKEY_INIT                  0
#   define CRMF_F_OSSL_CRMF_CERTID_GEN                      0
#   define CRMF_F_OSSL_CRMF_CERTTEMPLATE_FILL               0
#   define CRMF_F_OSSL_CRMF_ENCRYPTEDVALUE_GET1_ENCCERT     0
#   define CRMF_F_OSSL_CRMF_MSGS_VERIFY_POPO                0
#   define CRMF_F_OSSL_CRMF_MSG_CREATE_POPO                 0
#   define CRMF_F_OSSL_CRMF_MSG_GET0_TMPL                   0
#   define CRMF_F_OSSL_CRMF_MSG_GET_CERTREQID               0
#   define CRMF_F_OSSL_CRMF_MSG_PKIPUBLICATIONINFO_PUSH0_SINGLEPUBINFO 0
#   define CRMF_F_OSSL_CRMF_MSG_PUSH0_EXTENSION             0
#   define CRMF_F_OSSL_CRMF_MSG_PUSH0_REGCTRL               0
#   define CRMF_F_OSSL_CRMF_MSG_PUSH0_REGINFO               0
#   define CRMF_F_OSSL_CRMF_MSG_SET0_EXTENSIONS             0
#   define CRMF_F_OSSL_CRMF_MSG_SET0_SINGLEPUBINFO          0
#   define CRMF_F_OSSL_CRMF_MSG_SET_CERTREQID               0
#   define CRMF_F_OSSL_CRMF_MSG_SET_PKIPUBLICATIONINFO_ACTION 0
#   define CRMF_F_OSSL_CRMF_MSG_SET_VALIDITY                0
#   define CRMF_F_OSSL_CRMF_PBMP_NEW                        0
#   define CRMF_F_OSSL_CRMF_PBM_NEW                         0
# endif

/*
 * CRMF reason codes.
 */
#  define CRMF_R_BAD_PBM_ITERATIONCOUNT                    100
#  define CRMF_R_CRMFERROR                                 102
#  define CRMF_R_ERROR                                     103
#  define CRMF_R_ERROR_DECODING_CERTIFICATE                104
#  define CRMF_R_ERROR_DECRYPTING_CERTIFICATE              105
#  define CRMF_R_ERROR_DECRYPTING_SYMMETRIC_KEY            106
#  define CRMF_R_FAILURE_OBTAINING_RANDOM                  107
#  define CRMF_R_ITERATIONCOUNT_BELOW_100                  108
#  define CRMF_R_MALFORMED_IV                              101
#  define CRMF_R_NULL_ARGUMENT                             109
#  define CRMF_R_POPO_INCONSISTENT_PUBLIC_KEY              117
#  define CRMF_R_POPO_MISSING                              121
#  define CRMF_R_POPO_MISSING_PUBLIC_KEY                   118
#  define CRMF_R_POPO_MISSING_SUBJECT                      119
#  define CRMF_R_POPO_RAVERIFIED_NOT_ACCEPTED              120
#  define CRMF_R_SETTING_MAC_ALGOR_FAILURE                 110
#  define CRMF_R_SETTING_OWF_ALGOR_FAILURE                 111
#  define CRMF_R_UNSUPPORTED_ALGORITHM                     112
#  define CRMF_R_UNSUPPORTED_ALG_FOR_POPSIGNINGKEY         113
#  define CRMF_R_UNSUPPORTED_CIPHER                        114
#  define CRMF_R_UNSUPPORTED_METHOD_FOR_CREATING_POPO      115
#  define CRMF_R_UNSUPPORTED_POPO_METHOD                   116

# endif
#endif

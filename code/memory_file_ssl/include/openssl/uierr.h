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

#ifndef OPENSSL_UIERR_H
# define OPENSSL_UIERR_H
# pragma once

# include <openssl/opensslconf.h>
# include <openssl/symhacks.h>


# ifdef  __cplusplus
extern "C"
# endif
int ERR_load_UI_strings(void);

/*
 * UI function codes.
 */
# ifndef OPENSSL_NO_DEPRECATED_3_0
#  define UI_F_CLOSE_CONSOLE                               0
#  define UI_F_ECHO_CONSOLE                                0
#  define UI_F_GENERAL_ALLOCATE_BOOLEAN                    0
#  define UI_F_GENERAL_ALLOCATE_PROMPT                     0
#  define UI_F_NOECHO_CONSOLE                              0
#  define UI_F_OPEN_CONSOLE                                0
#  define UI_F_UI_CONSTRUCT_PROMPT                         0
#  define UI_F_UI_CREATE_METHOD                            0
#  define UI_F_UI_CTRL                                     0
#  define UI_F_UI_DUP_ERROR_STRING                         0
#  define UI_F_UI_DUP_INFO_STRING                          0
#  define UI_F_UI_DUP_INPUT_BOOLEAN                        0
#  define UI_F_UI_DUP_INPUT_STRING                         0
#  define UI_F_UI_DUP_USER_DATA                            0
#  define UI_F_UI_DUP_VERIFY_STRING                        0
#  define UI_F_UI_GET0_RESULT                              0
#  define UI_F_UI_GET_RESULT_LENGTH                        0
#  define UI_F_UI_NEW_METHOD                               0
#  define UI_F_UI_PROCESS                                  0
#  define UI_F_UI_SET_RESULT                               0
#  define UI_F_UI_SET_RESULT_EX                            0
# endif

/*
 * UI reason codes.
 */
# define UI_R_COMMON_OK_AND_CANCEL_CHARACTERS             104
# define UI_R_INDEX_TOO_LARGE                             102
# define UI_R_INDEX_TOO_SMALL                             103
# define UI_R_NO_RESULT_BUFFER                            105
# define UI_R_PROCESSING_ERROR                            107
# define UI_R_RESULT_TOO_LARGE                            100
# define UI_R_RESULT_TOO_SMALL                            101
# define UI_R_SYSASSIGN_ERROR                             109
# define UI_R_SYSDASSGN_ERROR                             110
# define UI_R_SYSQIOW_ERROR                               111
# define UI_R_UNKNOWN_CONTROL_COMMAND                     106
# define UI_R_UNKNOWN_TTYGET_ERRNO_VALUE                  108
# define UI_R_USER_DATA_DUPLICATION_UNSUPPORTED           112

#endif

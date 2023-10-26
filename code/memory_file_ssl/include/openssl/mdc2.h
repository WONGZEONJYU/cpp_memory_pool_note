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
 * Copyright 1995-2020 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef OPENSSL_MDC2_H
# define OPENSSL_MDC2_H
# pragma once

# include <openssl/macros.h>
# ifndef OPENSSL_NO_DEPRECATED_3_0
#  define HEADER_MDC2_H
# endif

# include <openssl/opensslconf.h>

# ifndef OPENSSL_NO_MDC2
#  include <stdlib.h>
#  include <openssl/des.h>
#  ifdef  __cplusplus
extern "C" {
#  endif

#  define MDC2_DIGEST_LENGTH      16

#  if !defined(OPENSSL_NO_DEPRECATED_3_0)

#   define MDC2_BLOCK              8

typedef struct mdc2_ctx_st {
    unsigned int num;
    unsigned char data[MDC2_BLOCK];
    DES_cblock h, hh;
    unsigned int pad_type;   /* either 1 or 2, default 1 */
} MDC2_CTX;
#  endif

DEPRECATEDIN_3_0(int MDC2_Init(MDC2_CTX *c))
DEPRECATEDIN_3_0(int MDC2_Update(MDC2_CTX *c, const unsigned char *data,
                 size_t len))
DEPRECATEDIN_3_0(int MDC2_Final(unsigned char *md, MDC2_CTX *c))
DEPRECATEDIN_3_0(unsigned char *MDC2(const unsigned char *d, size_t n,
                 unsigned char *md))

#  ifdef  __cplusplus
}
#  endif
# endif

#endif

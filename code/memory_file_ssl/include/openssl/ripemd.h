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

#ifndef OPENSSL_RIPEMD_H
# define OPENSSL_RIPEMD_H
# pragma once

# include <openssl/macros.h>
# ifndef OPENSSL_NO_DEPRECATED_3_0
#  define HEADER_RIPEMD_H
# endif

# include <openssl/opensslconf.h>

# ifndef OPENSSL_NO_RMD160
#  include <openssl/e_os2.h>
#  include <stddef.h>

#  define RIPEMD160_DIGEST_LENGTH 20

#  ifdef  __cplusplus
extern "C" {
#  endif
#  if !defined(OPENSSL_NO_DEPRECATED_3_0)

#   define RIPEMD160_LONG unsigned int

#   define RIPEMD160_CBLOCK        64
#   define RIPEMD160_LBLOCK        (RIPEMD160_CBLOCK/4)

typedef struct RIPEMD160state_st {
    RIPEMD160_LONG A, B, C, D, E;
    RIPEMD160_LONG Nl, Nh;
    RIPEMD160_LONG data[RIPEMD160_LBLOCK];
    unsigned int num;
} RIPEMD160_CTX;
#  endif

DEPRECATEDIN_3_0(int RIPEMD160_Init(RIPEMD160_CTX *c))
DEPRECATEDIN_3_0(int RIPEMD160_Update(RIPEMD160_CTX *c, const void *data,
                                      size_t len))
DEPRECATEDIN_3_0(int RIPEMD160_Final(unsigned char *md, RIPEMD160_CTX *c))
DEPRECATEDIN_3_0(unsigned char *RIPEMD160(const unsigned char *d, size_t n,
                                          unsigned char *md))
DEPRECATEDIN_3_0(void RIPEMD160_Transform(RIPEMD160_CTX *c,
                                          const unsigned char *b))

#  ifdef  __cplusplus
}
#  endif
# endif
#endif

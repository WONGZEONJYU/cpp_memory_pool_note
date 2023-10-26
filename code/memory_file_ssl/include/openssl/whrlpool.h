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
 * Copyright 2005-2020 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef OPENSSL_WHRLPOOL_H
# define OPENSSL_WHRLPOOL_H
# pragma once

# include <openssl/macros.h>
# ifndef OPENSSL_NO_DEPRECATED_3_0
#  define HEADER_WHRLPOOL_H
# endif

# include <openssl/opensslconf.h>

# ifndef OPENSSL_NO_WHIRLPOOL
#  include <openssl/e_os2.h>
#  include <stddef.h>
#  ifdef __cplusplus
extern "C" {
#  endif

#  define WHIRLPOOL_DIGEST_LENGTH (512/8)

#  if !defined(OPENSSL_NO_DEPRECATED_3_0)

#   define WHIRLPOOL_BBLOCK        512
#   define WHIRLPOOL_COUNTER       (256/8)

typedef struct {
    union {
        unsigned char c[WHIRLPOOL_DIGEST_LENGTH];
        /* double q is here to ensure 64-bit alignment */
        double q[WHIRLPOOL_DIGEST_LENGTH / sizeof(double)];
    } H;
    unsigned char data[WHIRLPOOL_BBLOCK / 8];
    unsigned int bitoff;
    size_t bitlen[WHIRLPOOL_COUNTER / sizeof(size_t)];
} WHIRLPOOL_CTX;
#  endif

DEPRECATEDIN_3_0(int WHIRLPOOL_Init(WHIRLPOOL_CTX *c))
DEPRECATEDIN_3_0(int WHIRLPOOL_Update(WHIRLPOOL_CTX *c,
                                      const void *inp, size_t bytes))
DEPRECATEDIN_3_0(void WHIRLPOOL_BitUpdate(WHIRLPOOL_CTX *c, const void *inp,
                                          size_t bits))
DEPRECATEDIN_3_0(int WHIRLPOOL_Final(unsigned char *md, WHIRLPOOL_CTX *c))
DEPRECATEDIN_3_0(unsigned char *WHIRLPOOL(const void *inp, size_t bytes,
                                          unsigned char *md))

#  ifdef __cplusplus
}
#  endif
# endif

#endif

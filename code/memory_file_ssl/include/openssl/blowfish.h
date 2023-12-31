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

#ifndef OPENSSL_BLOWFISH_H
# define OPENSSL_BLOWFISH_H
# pragma once

# include <openssl/macros.h>
# ifndef OPENSSL_NO_DEPRECATED_3_0
#  define HEADER_BLOWFISH_H
# endif

# include <openssl/opensslconf.h>

# ifndef OPENSSL_NO_BF
# include <openssl/e_os2.h>
# ifdef  __cplusplus
extern "C" {
# endif

# define BF_BLOCK        8

# ifndef OPENSSL_NO_DEPRECATED_3_0

#  define BF_ENCRYPT      1
#  define BF_DECRYPT      0

/*-
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * ! BF_LONG has to be at least 32 bits wide.                     !
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 */
#  define BF_LONG unsigned int

#  define BF_ROUNDS       16

typedef struct bf_key_st {
    BF_LONG P[BF_ROUNDS + 2];
    BF_LONG S[4 * 256];
} BF_KEY;

# endif /* OPENSSL_NO_DEPRECATED_3_0 */

DEPRECATEDIN_3_0(void BF_set_key(BF_KEY *key, int len,
                                 const unsigned char *data))

DEPRECATEDIN_3_0(void BF_encrypt(BF_LONG *data, const BF_KEY *key))
DEPRECATEDIN_3_0(void BF_decrypt(BF_LONG *data, const BF_KEY *key))

DEPRECATEDIN_3_0(void BF_ecb_encrypt(const unsigned char *in,
                                     unsigned char *out, const BF_KEY *key,
                                     int enc))
DEPRECATEDIN_3_0(void BF_cbc_encrypt(const unsigned char *in,
                                     unsigned char *out, long length,
                                     const BF_KEY *schedule,
                                     unsigned char *ivec, int enc))
DEPRECATEDIN_3_0(void BF_cfb64_encrypt(const unsigned char *in,
                                       unsigned char *out,
                                       long length, const BF_KEY *schedule,
                                       unsigned char *ivec, int *num, int enc))
DEPRECATEDIN_3_0(void BF_ofb64_encrypt(const unsigned char *in,
                                       unsigned char *out,
                                       long length, const BF_KEY *schedule,
                                       unsigned char *ivec, int *num))
DEPRECATEDIN_3_0(const char *BF_options(void))

# ifdef  __cplusplus
}
# endif
# endif

#endif

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

#ifndef OPENSSL_RC5_H
# define OPENSSL_RC5_H
# pragma once

# include <openssl/macros.h>
# ifndef OPENSSL_NO_DEPRECATED_3_0
#  define HEADER_RC5_H
# endif

# include <openssl/opensslconf.h>

# ifndef OPENSSL_NO_RC5
#  ifdef  __cplusplus
extern "C" {
#  endif

#  define RC5_32_BLOCK            8
#  define RC5_32_KEY_LENGTH       16/* This is a default, max is 255 */

#  ifndef OPENSSL_NO_DEPRECATED_3_0
#   define RC5_ENCRYPT     1
#   define RC5_DECRYPT     0

#   define RC5_32_INT unsigned int

/*
 * This are the only values supported.  Tweak the code if you want more The
 * most supported modes will be RC5-32/12/16 RC5-32/16/8
 */
#   define RC5_8_ROUNDS    8
#   define RC5_12_ROUNDS   12
#   define RC5_16_ROUNDS   16

typedef struct rc5_key_st {
    /* Number of rounds */
    int rounds;
    RC5_32_INT data[2 * (RC5_16_ROUNDS + 1)];
} RC5_32_KEY;
#  endif

DEPRECATEDIN_3_0(int RC5_32_set_key(RC5_32_KEY *key, int len,
                                    const unsigned char *data, int rounds))
DEPRECATEDIN_3_0(void RC5_32_ecb_encrypt(const unsigned char *in,
                                         unsigned char *out, RC5_32_KEY *key,
                                         int enc))
DEPRECATEDIN_3_0(void RC5_32_encrypt(unsigned long *data, RC5_32_KEY *key))
DEPRECATEDIN_3_0(void RC5_32_decrypt(unsigned long *data, RC5_32_KEY *key))
DEPRECATEDIN_3_0(void RC5_32_cbc_encrypt(const unsigned char *in,
                                         unsigned char *out, long length,
                                         RC5_32_KEY *ks, unsigned char *iv,
                                         int enc))
DEPRECATEDIN_3_0(void RC5_32_cfb64_encrypt(const unsigned char *in,
                                           unsigned char *out, long length,
                                           RC5_32_KEY *schedule,
                                           unsigned char *ivec, int *num,
                                           int enc))
DEPRECATEDIN_3_0(void RC5_32_ofb64_encrypt(const unsigned char *in,
                                           unsigned char *out, long length,
                                           RC5_32_KEY *schedule,
                                           unsigned char *ivec, int *num))

#  ifdef  __cplusplus
}
#  endif
# endif

#endif

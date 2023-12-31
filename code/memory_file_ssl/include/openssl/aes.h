//////////////////////////////////  @版权说明  //////////////////////////////////////////////////
///						Jiedi(China nanjing)Ltd.                                    
/// @版权说明 代码和课程版权有夏曹俊所拥有并已经申请著作权，此代码可用作为学习参考并可在项目中使用，
/// 课程中涉及到的其他开源软件，请遵守其相应的授权
/// 课程源码不可以直接转载到公开的博客，或者其他共享平台，不可以用以制作在线课程。
/// 课程中涉及到的其他开源软件，请遵守其相应的授权  @@              
/////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////  源码说明  //////////////////////////////////////////////////
/// 项目名称      : C++ 11 14 17 20内存管理-指针、智能指针和内存池从基础到实战
/// Contact       : xiacaojun@qq.com
///  博客   :				http://blog.csdn.net/jiedichina
///	视频课程 : 网易云课堂	http://study.163.com/u/xiacaojun		
///			   腾讯课堂		https://jiedi.ke.qq.com/				
///			   csdn学院		http://edu.csdn.net/lecturer/lecturer_detail?lecturer_id=961	
///           51cto学院		https://edu.51cto.com/sd/d3b6d
///			   老夏课堂		http://cppds.com 
/// 更多资料请在此网页下载  http://ffmpeg.club
/// ！！！请加入课程qq群 【296249312】与同学交流 
/// 微信公众号: jiedi2007
/// 头条号	 : xiacaojun
///加入老夏课堂群【296249312】直接联系群里客服下载课程资料
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// 课程交流qq群296249312 //////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////// COMMENT ///////////////////////////////////////////////



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
 * Copyright 2002-2020 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef OPENSSL_AES_H
# define OPENSSL_AES_H
# pragma once

# include <openssl/macros.h>
# ifndef OPENSSL_NO_DEPRECATED_3_0
#  define HEADER_AES_H
# endif

# include <openssl/opensslconf.h>

# include <stddef.h>
# ifdef  __cplusplus
extern "C" {
# endif

# define AES_BLOCK_SIZE 16

# ifndef OPENSSL_NO_DEPRECATED_3_0

#  define AES_ENCRYPT     1
#  define AES_DECRYPT     0

#  define AES_MAXNR 14


/* This should be a hidden type, but EVP requires that the size be known */
struct aes_key_st {
#  ifdef AES_LONG
    unsigned long rd_key[4 * (AES_MAXNR + 1)];
#  else
    unsigned int rd_key[4 * (AES_MAXNR + 1)];
#  endif
    int rounds;
};
typedef struct aes_key_st AES_KEY;

# endif

DEPRECATEDIN_3_0(const char *AES_options(void))

DEPRECATEDIN_3_0(int
                 AES_set_encrypt_key(const unsigned char *userKey,
                                     const int bits, AES_KEY *key))
DEPRECATEDIN_3_0(int
                 AES_set_decrypt_key(const unsigned char *userKey,
                                     const int bits, AES_KEY *key))

DEPRECATEDIN_3_0(void
                 AES_encrypt(const unsigned char *in, unsigned char *out,
                             const AES_KEY *key))
DEPRECATEDIN_3_0(void
                 AES_decrypt(const unsigned char *in, unsigned char *out,
                             const AES_KEY *key))

DEPRECATEDIN_3_0(void
                 AES_ecb_encrypt(const unsigned char *in, unsigned char *out,
                                 const AES_KEY *key, const int enc))
DEPRECATEDIN_3_0(void
                 AES_cbc_encrypt(const unsigned char *in, unsigned char *out,
                                 size_t length, const AES_KEY *key,
                                 unsigned char *ivec, const int enc))
DEPRECATEDIN_3_0(void
                 AES_cfb128_encrypt(const unsigned char *in, unsigned char *out,
                                    size_t length, const AES_KEY *key,
                                    unsigned char *ivec, int *num,
                                    const int enc))
DEPRECATEDIN_3_0(void
                 AES_cfb1_encrypt(const unsigned char *in, unsigned char *out,
                                  size_t length, const AES_KEY *key,
                                  unsigned char *ivec, int *num, const int enc))
DEPRECATEDIN_3_0(void
                 AES_cfb8_encrypt(const unsigned char *in, unsigned char *out,
                                  size_t length, const AES_KEY *key,
                                  unsigned char *ivec, int *num, const int enc))
DEPRECATEDIN_3_0(void
                 AES_ofb128_encrypt(const unsigned char *in, unsigned char *out,
                                    size_t length, const AES_KEY *key,
                                    unsigned char *ivec, int *num))

/* NB: the IV is _two_ blocks long */
DEPRECATEDIN_3_0(void
                 AES_ige_encrypt(const unsigned char *in, unsigned char *out,
                                 size_t length, const AES_KEY *key,
                                 unsigned char *ivec, const int enc))
/* NB: the IV is _four_ blocks long */
DEPRECATEDIN_3_0(void
                 AES_bi_ige_encrypt(const unsigned char *in, unsigned char *out,
                                    size_t length, const AES_KEY *key,
                                    const AES_KEY *key2,
                                    const unsigned char *ivec, const int enc))

DEPRECATEDIN_3_0(int
                 AES_wrap_key(AES_KEY *key, const unsigned char *iv,
                              unsigned char *out, const unsigned char *in,
                              unsigned int inlen))
DEPRECATEDIN_3_0(int
                 AES_unwrap_key(AES_KEY *key, const unsigned char *iv,
                                unsigned char *out, const unsigned char *in,
                                unsigned int inlen))


# ifdef  __cplusplus
}
# endif

#endif

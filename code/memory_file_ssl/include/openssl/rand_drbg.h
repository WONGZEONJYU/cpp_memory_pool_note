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
 * Copyright 2017-2020 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef OPENSSL_RAND_DRBG_H
# define OPENSSL_RAND_DRBG_H
# pragma once

# include <openssl/macros.h>
# ifndef OPENSSL_NO_DEPRECATED_3_0
#  define HEADER_DRBG_RAND_H
# endif

# include <time.h>
# include <openssl/types.h>
# include <openssl/obj_mac.h>

/*
 * RAND_DRBG  flags
 *
 * Note: if new flags are added, the constant `rand_drbg_used_flags`
 *       in drbg_lib.c needs to be updated accordingly.
 */

/* In CTR mode, disable derivation function ctr_df */
# define RAND_DRBG_FLAG_CTR_NO_DF            0x1
/*
 * This flag is only used when a digest NID is specified (i.e: not a CTR cipher)
 * Selects DRBG_HMAC if this is set otherwise use DRBG_HASH.
 */
# define RAND_DRBG_FLAG_HMAC                 0x2

/* Used by RAND_DRBG_set_defaults() to set the master DRBG type and flags. */
# define RAND_DRBG_FLAG_MASTER               0x4
/* Used by RAND_DRBG_set_defaults() to set the public DRBG type and flags. */
# define RAND_DRBG_FLAG_PUBLIC               0x8
/* Used by RAND_DRBG_set_defaults() to set the private DRBG type and flags. */
# define RAND_DRBG_FLAG_PRIVATE              0x10

# ifndef OPENSSL_NO_DEPRECATED_3_0
/* This #define was replaced by an internal constant and should not be used. */
#  define RAND_DRBG_USED_FLAGS  (RAND_DRBG_FLAG_CTR_NO_DF)
# endif

/*
 * Default security strength (in the sense of [NIST SP 800-90Ar1])
 *
 * NIST SP 800-90Ar1 supports the strength of the DRBG being smaller than that
 * of the cipher by collecting less entropy. The current DRBG implementation
 * does not take RAND_DRBG_STRENGTH into account and sets the strength of the
 * DRBG to that of the cipher.
 *
 * RAND_DRBG_STRENGTH is currently only used for the legacy RAND
 * implementation.
 *
 * Currently supported ciphers are: NID_aes_128_ctr, NID_aes_192_ctr and
 * NID_aes_256_ctr.
 * The digest types for DRBG_hash or DRBG_hmac are: NID_sha1, NID_sha224,
 * NID_sha256, NID_sha384, NID_sha512, NID_sha512_224, NID_sha512_256,
 * NID_sha3_224, NID_sha3_256, NID_sha3_384 and NID_sha3_512.
 */
# define RAND_DRBG_STRENGTH             256
/* Default drbg type */
# define RAND_DRBG_TYPE                 NID_aes_256_ctr
/* Default drbg flags */
# define RAND_DRBG_FLAGS                0


# ifdef  __cplusplus
extern "C" {
# endif

/*
 * Object lifetime functions.
 */
RAND_DRBG *RAND_DRBG_new_ex(OPENSSL_CTX *ctx, int type, unsigned int flags,
                            RAND_DRBG *parent);
RAND_DRBG *RAND_DRBG_secure_new_ex(OPENSSL_CTX *ctx, int type,
                                   unsigned int flags, RAND_DRBG *parent);
RAND_DRBG *RAND_DRBG_new(int type, unsigned int flags, RAND_DRBG *parent);
RAND_DRBG *RAND_DRBG_secure_new(int type, unsigned int flags, RAND_DRBG *parent);
int RAND_DRBG_set(RAND_DRBG *drbg, int type, unsigned int flags);
int RAND_DRBG_set_defaults(int type, unsigned int flags);
int RAND_DRBG_instantiate(RAND_DRBG *drbg,
                          const unsigned char *pers, size_t perslen);
int RAND_DRBG_uninstantiate(RAND_DRBG *drbg);
void RAND_DRBG_free(RAND_DRBG *drbg);

/*
 * Object "use" functions.
 */
int RAND_DRBG_reseed(RAND_DRBG *drbg,
                     const unsigned char *adin, size_t adinlen,
                     int prediction_resistance);
int RAND_DRBG_generate(RAND_DRBG *drbg, unsigned char *out, size_t outlen,
                       int prediction_resistance,
                       const unsigned char *adin, size_t adinlen);
int RAND_DRBG_bytes(RAND_DRBG *drbg, unsigned char *out, size_t outlen);

int RAND_DRBG_set_reseed_interval(RAND_DRBG *drbg, unsigned int interval);
int RAND_DRBG_set_reseed_time_interval(RAND_DRBG *drbg, time_t interval);

int RAND_DRBG_set_reseed_defaults(
                                  unsigned int master_reseed_interval,
                                  unsigned int slave_reseed_interval,
                                  time_t master_reseed_time_interval,
                                  time_t slave_reseed_time_interval
                                  );

RAND_DRBG *OPENSSL_CTX_get0_master_drbg(OPENSSL_CTX *ctx);
RAND_DRBG *OPENSSL_CTX_get0_public_drbg(OPENSSL_CTX *ctx);
RAND_DRBG *OPENSSL_CTX_get0_private_drbg(OPENSSL_CTX *ctx);
RAND_DRBG *RAND_DRBG_get0_master(void);
RAND_DRBG *RAND_DRBG_get0_public(void);
RAND_DRBG *RAND_DRBG_get0_private(void);

/*
 * EXDATA
 */
# define RAND_DRBG_get_ex_new_index(l, p, newf, dupf, freef) \
    CRYPTO_get_ex_new_index(CRYPTO_EX_INDEX_RAND_DRBG, l, p, newf, dupf, freef)
int RAND_DRBG_set_ex_data(RAND_DRBG *drbg, int idx, void *arg);
void *RAND_DRBG_get_ex_data(const RAND_DRBG *drbg, int idx);

/*
 * Callback function typedefs
 */
typedef size_t (*RAND_DRBG_get_entropy_fn)(RAND_DRBG *drbg,
                                           unsigned char **pout,
                                           int entropy, size_t min_len,
                                           size_t max_len,
                                           int prediction_resistance);
typedef void (*RAND_DRBG_cleanup_entropy_fn)(RAND_DRBG *ctx,
                                             unsigned char *out, size_t outlen);
typedef size_t (*RAND_DRBG_get_nonce_fn)(RAND_DRBG *drbg, unsigned char **pout,
                                         int entropy, size_t min_len,
                                         size_t max_len);
typedef void (*RAND_DRBG_cleanup_nonce_fn)(RAND_DRBG *drbg,
                                           unsigned char *out, size_t outlen);

int RAND_DRBG_set_callbacks(RAND_DRBG *drbg,
                            RAND_DRBG_get_entropy_fn get_entropy,
                            RAND_DRBG_cleanup_entropy_fn cleanup_entropy,
                            RAND_DRBG_get_nonce_fn get_nonce,
                            RAND_DRBG_cleanup_nonce_fn cleanup_nonce);


int RAND_DRBG_set_callback_data(RAND_DRBG *drbg, void *data);

void *RAND_DRBG_get_callback_data(RAND_DRBG *drbg);

# ifdef  __cplusplus
}
# endif

#endif

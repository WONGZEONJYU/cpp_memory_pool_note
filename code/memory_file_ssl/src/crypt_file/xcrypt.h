#ifndef XCRYPT_H_
#define XCRYPT_H_

#include <string>
#include <openssl/des.h>

class XCrypt
{
public:
	explicit XCrypt() = default;
	explicit XCrypt(std::string password);
	/// <summary>
	/// 初始化密钥 , DES加密算法 密钥最多8bit 多余丢弃不足补0
	/// </summary>
	/// <param name="password"></param>
	/// <returns>ture or false</returns>

	bool Init(std::string password);

	 /// <summary>
	 /// 加密数据,结尾填充补充的大小 加密数据大小如果不是 8, 16的倍数
	 /// </summary>
	 /// <param name="in_data">输入数据</param>
	 /// <param name="insize">输入数据大小</param>
	 /// <param name="out_data">输出数据</param>
	 /// <param name="is_end">是否到加密结尾</param>
	 /// <returns>0 or size 返回加密后数据大小, 有可能大于输入 , 添加补充</returns>

	size_t Encrypt(const char* in_data,size_t insize,
		char* out_data, bool is_end = false) ;

	 /// <summary>
	 /// 解密数据,结尾去掉填充大小
	 /// </summary>
	 /// <param name="in_data">输入数据</param>
	 /// <param name="insize">输入数据大小</param>
	 /// <param name="out_data">输出数据</param>
	 /// <param name="is_end">是否到加密结尾</param>
	 /// <returns>-1 or size 返回解密后数据大小 , 有可能小于输入 , 去掉补充</returns>

	size_t Decrypt(const char* in_data, size_t insize,
		char* out_data,bool is_end = false);

	/// <summary>
	/// 获取需要填充的数据字节数
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	size_t Getpadding(size_t);

private:
	/*存储密钥*/
	DES_key_schedule key_sch_ {};
};

#endif

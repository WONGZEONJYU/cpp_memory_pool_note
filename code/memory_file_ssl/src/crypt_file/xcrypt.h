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
	/// ��ʼ����Կ , DES�����㷨 ��Կ���8bit ���ඪ�����㲹0
	/// </summary>
	/// <param name="password"></param>
	/// <returns>ture or false</returns>

	bool Init(std::string password);

	 /// <summary>
	 /// ��������,��β��䲹��Ĵ�С �������ݴ�С������� 8, 16�ı���
	 /// </summary>
	 /// <param name="in_data">��������</param>
	 /// <param name="insize">�������ݴ�С</param>
	 /// <param name="out_data">�������</param>
	 /// <param name="is_end">�Ƿ񵽼��ܽ�β</param>
	 /// <returns>0 or size ���ؼ��ܺ����ݴ�С, �п��ܴ������� , ��Ӳ���</returns>

	size_t Encrypt(const char* in_data,size_t insize,
		char* out_data, bool is_end = false) ;

	 /// <summary>
	 /// ��������,��βȥ������С
	 /// </summary>
	 /// <param name="in_data">��������</param>
	 /// <param name="insize">�������ݴ�С</param>
	 /// <param name="out_data">�������</param>
	 /// <param name="is_end">�Ƿ񵽼��ܽ�β</param>
	 /// <returns>-1 or size ���ؽ��ܺ����ݴ�С , �п���С������ , ȥ������</returns>

	size_t Decrypt(const char* in_data, size_t insize,
		char* out_data,bool is_end = false);

	/// <summary>
	/// ��ȡ��Ҫ���������ֽ���
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	size_t Getpadding(size_t);

private:
	/*�洢��Կ*/
	DES_key_schedule key_sch_ {};
};

#endif

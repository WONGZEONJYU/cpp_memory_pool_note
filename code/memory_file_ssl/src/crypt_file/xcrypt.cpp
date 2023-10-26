#include "xcrypt.h"

/*��ʼ����Կ , DES�����㷨 ��Կ���8bit ���ඪ�����㲹0*/
bool XCrypt::Init(std::string password)
{
    const_DES_cblock key{}; /*���㲹0,��ʼ������0*/
    auto key_size{ password.size()};

    if (key_size > sizeof(key)){ /*���ඪ��*/
        key_size = sizeof(key);
    }
    
    memcpy(key, password.c_str(), key_size);
    (void)DES_set_key(&key,&key_sch_);
    return true;
}

/// <summary>
/// ��������,��β��䲹��Ĵ�С �������ݴ�С������� 8, 16�ı���
/// </summary>
/// <param name="in_data">��������</param>
/// <param name="insize">�������ݴ�С</param>
/// <param name="out_data">�������</param>
/// <param name="is_end">�Ƿ񵽼��ܽ�β</param>
/// <returns>0 or size ���ؼ��ܺ����ݴ�С, �п��ܴ������� , ��Ӳ���</returns>
/// 
/// 
size_t XCrypt::Encrypt(const char* in_data, const size_t insize, char* out_data, bool is_end)
{
    if ((!in_data) || (!out_data) || (insize <= 0)) {
        return -1;
    }

    const_DES_cblock in{}; /*��������*/
    DES_cblock out{};/*���*/
    const auto block_size {sizeof(const_DES_cblock)};
    size_t write_size{}, data_size{};

    for (size_t i{}; i < insize; i+= block_size){

        const auto temp_v{ insize - i };

        if (temp_v < block_size) {
            data_size = temp_v;
        }else {
            data_size = block_size;
        }

        memcpy(in, in_data + write_size, data_size);

        /*��� ��������ݴ�С @@@@@@@1 @@@55555 @@@@@@@@88888888*/
        const auto r{ (i + block_size) >= insize };

        if (is_end && r){

        }

        DES_ecb_encrypt(&in,&out,&key_sch_,DES_ENCRYPT);
        memcpy(out_data + write_size, &out, block_size);
        write_size += block_size;
    }

    return write_size;
}

size_t XCrypt::Decrypt(const char* in_data, size_t insize, char* out_data, bool is_end)
{
    return 0;
}

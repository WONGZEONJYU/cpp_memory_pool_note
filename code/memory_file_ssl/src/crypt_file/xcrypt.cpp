#include "xcrypt.h"
#include <iostream>

using namespace std;

XCrypt::XCrypt(std::string password)
{
    Init(std::move(password));
}

/*��ʼ����Կ , DES�����㷨 ��Կ���8bit ���ඪ�����㲹0*/
bool XCrypt::Init(string password)
{
    const_DES_cblock key{}; /*���㲹0,��ʼ������0*/
    auto key_size{ password.size()};

    if (key_size > sizeof(key)){ /*���ඪ��*/
        key_size = sizeof(key);
    }
    memcpy(key, password.c_str(), key_size);
    (void)DES_set_key(&key, &key_sch_);
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
size_t XCrypt::Encrypt(const char* in_data, const size_t insize, char* out_data, const bool is_end)
{
    if ((!in_data) || (!out_data) || (insize <= 0)) {
        return 0;
    }

    const auto block_size{ sizeof(const_DES_cblock) }, over{ insize % block_size },
        padding{ block_size - over };

    size_t write_size{}, data_size{};

    for (size_t i{}; i < insize; i+= block_size){

        const auto temp_v{ insize - i };

        data_size = (temp_v < block_size) ? temp_v : block_size;

        const_DES_cblock in{}; /*����(δ��������)*/
        DES_cblock out{};/*���(���ܺ�����)*/

        memcpy(in, in_data + write_size, data_size);

        /*��� ��������ݴ�С @@@@@@@1 @@@55555 @@@@@@@@88888888*/

        const auto is_{ is_end && ((i + block_size) >= insize) };

        if (is_){
            //@@@@@@@@8888888
            if (padding == block_size) { /*�����8���ֽ�*/
                DES_ecb_encrypt(&in, &out, &key_sch_, DES_ENCRYPT);
                memcpy(out_data + write_size, &out, block_size);
                write_size += block_size;
                memset(in, padding, sizeof(in)); //���8
            }else{ //@@@@@@@1   @@@55555
                memset(in + over, padding, padding);
            }
        }

        DES_ecb_encrypt(&in,&out,&key_sch_,DES_ENCRYPT);
        memcpy(out_data + write_size, &out, block_size);
        write_size += block_size;
    }

    return write_size;
}

/// <summary>
/// ��������,��βȥ������С
/// </summary>
/// <param name="in_data">��������</param>
/// <param name="insize">�������ݴ�С</param>
/// <param name="out_data">�������</param>
/// <param name="is_end">�Ƿ񵽼��ܽ�β</param>
/// <returns>-1 or size ���ؽ��ܺ����ݴ�С , �п���С������ , ȥ������</returns>

size_t XCrypt::Decrypt(const char* in_data, const size_t insize, char* out_data, const bool is_end)
{
    if ((!in_data) || (!out_data) || (insize <= 0)) {
        return 0;
    }

    const auto block_size{ sizeof(const_DES_cblock) }, over{ insize % block_size },
        padding{ block_size - over };

    size_t write_size{}, data_size{};

    for (size_t i {}; i < insize; i+= block_size) {

        const_DES_cblock in{}; /*����(�Ѽ�������)*/
        DES_cblock out{};/*���(���ܺ�����)*/

        memcpy(&in, in_data + write_size, block_size);
        DES_ecb_encrypt(&in, &out, &key_sch_, DES_DECRYPT); /*����*/

        data_size = block_size;/*Ĭ�����data_size == block_size*/

        /*�����β��*/

        /*������ݳ��Ȳ���8�ı�������ô���һ�����ݲ���8���ֽڵ�λ�ö��ᱻ���Ϊʣ��ĳ��ȴ�С�����ֵ
        * ���� @@@55555 , 5�Ǵӵ�����λ�ÿ�ʼ���,����βҲ��5,����out[7] == 5
        */

        const auto is_ { is_end && ((insize - i) <= block_size)};

        if (is_){

            data_size = block_size - out[7]; 
            /*ͨ�����һ��Ԫ�ص�ֵ���Լ�������追�����ٸ�����*/

            if (!data_size){ /*�����8�ı���,data_size == 0*/
                break;
            }else if(data_size < 0){ /*�쳣���*/
                cerr << "Decrypt failed!padding size error\n";
                break;
            }else { /*�������*/

            }
        }

        memcpy(out_data + write_size, &out, data_size);
        write_size += block_size;
    }

    return write_size;
}

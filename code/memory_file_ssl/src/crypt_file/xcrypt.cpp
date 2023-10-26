#include "xcrypt.h"

/*初始化密钥 , DES加密算法 密钥最多8bit 多余丢弃不足补0*/
bool XCrypt::Init(std::string password)
{
    const_DES_cblock key{}; /*不足补0,初始化就置0*/
    auto key_size{ password.size()};

    if (key_size > sizeof(key)){ /*多余丢弃*/
        key_size = sizeof(key);
    }
    
    memcpy(key, password.c_str(), key_size);
    (void)DES_set_key(&key,&key_sch_);
    return true;
}

/// <summary>
/// 加密数据,结尾填充补充的大小 加密数据大小如果不是 8, 16的倍数
/// </summary>
/// <param name="in_data">输入数据</param>
/// <param name="insize">输入数据大小</param>
/// <param name="out_data">输出数据</param>
/// <param name="is_end">是否到加密结尾</param>
/// <returns>0 or size 返回加密后数据大小, 有可能大于输入 , 添加补充</returns>
/// 
/// 
size_t XCrypt::Encrypt(const char* in_data, const size_t insize, char* out_data, bool is_end)
{
    if ((!in_data) || (!out_data) || (insize <= 0)) {
        return -1;
    }

    const_DES_cblock in{}; /*输入数据*/
    DES_cblock out{};/*输出*/
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

        /*填充 补充的数据大小 @@@@@@@1 @@@55555 @@@@@@@@88888888*/
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

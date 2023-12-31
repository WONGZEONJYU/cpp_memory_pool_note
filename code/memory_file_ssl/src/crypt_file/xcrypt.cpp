#include "xcrypt.h"
#include <iostream>
#include "x_exception.h"

using namespace std;

uint64_t XCrypt::Getpadding(const uint64_t _datasize)
{
    constexpr auto block_size{ sizeof(const_DES_cblock) };

    auto const over{ _datasize % block_size },
       padding{ block_size - over };

    return padding ? padding : block_size;
}

/*初始化密钥 , DES加密算法 密钥最多8bit 多余丢弃不足补0*/
void XCrypt::Init(string password) noexcept(false)
{
    if (password.empty()){
        throw XException(string(__FUNCTION__) + "password is empty!\n");
    }

    const_DES_cblock key{}; /*不足补0,初始化就置0*/
    auto key_size{ password.size()};

    if (key_size > sizeof(key)){ /*多余丢弃*/
        key_size = sizeof(key);
    }

    auto t_str{ password.c_str() };
    std::copy(t_str, t_str + key_size , key);
    DES_set_key(&key, &key_sch_);
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
uint64_t XCrypt::Encrypt(const char* in_data, const uint64_t insize,
    char* out_data, const bool is_end) noexcept(false)
{
    if ((!in_data) || (!out_data) || (insize <= 0)) {
        throw XException(string(__FUNCTION__) + "pointer or size is empty!\n");
    }

    constexpr auto block_size{ sizeof(const_DES_cblock) };
    const auto over{ insize % block_size },
        padding{ block_size - over };

    uint64_t write_size{}, data_size{};

    for (size_t i{}; i < insize; i+= block_size){

        const auto temp_v{ insize - i };

        data_size = (temp_v < block_size) ? temp_v : block_size;

        const_DES_cblock in{}; /*输入(未加密数据)*/
        DES_cblock out{};/*输出(加密后数据)*/

        std::copy(in_data + write_size, in_data + write_size + data_size, in);
        /*填充 补充的数据大小 @@@@@@@1 @@@55555 @@@@@@@@88888888*/

        const auto is_{ is_end && ((i + block_size) >= insize) };

        if (is_){
            //@@@@@@@@8888888
            if (padding == block_size) { /*补充多8个字节*/

                DES_ecb_encrypt(&in, &out, &key_sch_, DES_ENCRYPT);

                //memcpy(out_data + write_size, &out, block_size);
                std::copy(out, out + block_size , out_data + write_size);

                write_size += block_size;

                memset(in, static_cast<int>(padding), sizeof(in)); //填充8
            }else{ //@@@@@@@1   @@@55555
                memset(in + over, static_cast<int>(padding), static_cast<int>(padding));
            }
        }

        DES_ecb_encrypt(&in,&out,&key_sch_,DES_ENCRYPT);

        //memcpy(out_data + write_size, &out, block_size);
        std::copy(out, out + block_size, out_data + write_size);
        write_size += block_size;
    }

    return write_size;
}

/// <summary>
/// 解密数据,结尾去掉填充大小
/// </summary>
/// <param name="in_data">输入数据</param>
/// <param name="insize">输入数据大小</param>
/// <param name="out_data">输出数据</param>
/// <param name="is_end">是否到加密结尾</param>
/// <returns>-1 or size 返回解密后数据大小 , 有可能小于输入 , 去掉补充</returns>

uint64_t XCrypt::Decrypt(const char* in_data, const uint64_t insize,
    char* out_data, const bool is_end) noexcept(false)
{
    if ((!in_data) || (!out_data) || (insize <= 0)) {
        throw XException(string(__FUNCTION__) + "pointer or size is empty!\n");
    }

    constexpr auto block_size{ sizeof(const_DES_cblock) };
    const auto over{ insize % block_size },
        padding{ block_size - over };

    size_t write_size{}, data_size{};

    for (size_t i {}; i < insize; i+= block_size) {

        const_DES_cblock in{}; /*输入(已加密数据)*/
        DES_cblock out{};/*输出(解密后数据)*/

        //memcpy(&in, in_data + write_size, block_size);
        std::copy(in_data + write_size, in_data + write_size + block_size, in);

        DES_ecb_encrypt(&in, &out, &key_sch_, DES_DECRYPT); /*解密*/

        data_size = block_size;/*默认情况data_size == block_size*/

        /*处理结尾处*/

        /*如果数据长度不是8的倍数，那么最后一块数据不足8个字节的位置都会被填充为剩余的长度大小这个数值
        * 比如 @@@55555 , 5是从第三个位置开始填充,到结尾也是5,所以out[7] == 5
        */

        const auto is_ { is_end && ((insize - i) <= block_size)};

        if (is_){

            data_size = block_size - out[7]; 
            /*通过最后一个元素的值可以计算出还需拷贝多少个数据*/

            if (!data_size){ /*如果是8的倍数,data_size == 0*/
                break;
            }else if(data_size < 0){ /*异常情况*/
                cerr << "Decrypt failed!padding size error\n";
                break;
            }else { /*正常情况*/

            }
        }

        memcpy(out_data + write_size, &out, data_size);
        write_size += block_size;
    }

    return write_size;
}



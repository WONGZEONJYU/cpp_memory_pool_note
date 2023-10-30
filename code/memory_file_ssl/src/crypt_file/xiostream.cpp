#include "xiostream.h"

using namespace std;

/// <summary>
/// �߳�����
/// </summary>
void XIOStream::Start() {
	th_ = thread(&XIOStream::Main, this);
}

/// <summary>
/// �ȴ��߳��˳�
/// </summary>
void XIOStream::Wait() {
	if (th_.joinable()) {
		th_.join();
	}
}
/// <summary>
/// �߳��˳�,��Ҫ��Wait�ȴ�
/// </summary>
void XIOStream::Stop() {
	is_exit_ = true;
}
/// <summary>
/// �����ļ���С
/// </summary>
/// <param name=""></param>
void XIOStream::Ass_data_byte(const uint64_t n) {
	data_byte_ = n;
}
/// <summary>
/// ��ȡ�ļ���С
/// </summary>
/// <returns></returns>
uint64_t XIOStream::xs_data_byte() const {
	return data_byte_;
}

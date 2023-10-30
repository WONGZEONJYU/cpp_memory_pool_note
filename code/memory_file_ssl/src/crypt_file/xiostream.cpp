#include "xiostream.h"

using namespace std;

/// <summary>
/// 线程启动
/// </summary>
void XIOStream::Start() {
	th_ = thread(&XIOStream::Main, this);
}

/// <summary>
/// 等待线程退出
/// </summary>
void XIOStream::Wait() {
	if (th_.joinable()) {
		th_.join();
	}
}
/// <summary>
/// 线程退出,需要用Wait等待
/// </summary>
void XIOStream::Stop() {
	is_exit_ = true;
}
/// <summary>
/// 保存文件大小
/// </summary>
/// <param name=""></param>
void XIOStream::Ass_data_byte(const uint64_t n) {
	data_byte_ = n;
}
/// <summary>
/// 获取文件大小
/// </summary>
/// <returns></returns>
uint64_t XIOStream::xs_data_byte() const {
	return data_byte_;
}

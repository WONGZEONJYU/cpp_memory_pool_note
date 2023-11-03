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

/// <summary>
/// 设置内存池
/// </summary>
/// <param name=""></param>
void XIOStream::set_mem_pool(const _sp_mrs_type& p) {
	mem_pool_ = p;
}

void XIOStream::set_next(const _sp_xios_type& next) {
	next_ = next;
}

/// <summary>
/// 给对象传递数据,线程安全
/// </summary>
/// <param name="_data"></param>
void XIOStream::PushBack(const _sp_xdata_type& _data) {
	unique_lock<mutex> lock(mux_);
	datas_.push_back(_data);
	/*考虑最大列表问题?*/
}

XIOStream::_sp_xdata_type XIOStream::PopFront()
{
	unique_lock<mutex> lock(mux_);
	if (datas_.empty()){
		return {};
	}
	const auto re{ datas_.front() };
	datas_.pop_front();
	return re;
}


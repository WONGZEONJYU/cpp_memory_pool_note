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

/// <summary>
/// �����ڴ��
/// </summary>
/// <param name=""></param>
void XIOStream::set_mem_pool(const _sp_mrs_type& p) {
	mem_pool_ = p;
}

void XIOStream::set_next(const _sp_xios_type& next) {
	next_ = next;
}

/// <summary>
/// �����󴫵�����,�̰߳�ȫ
/// </summary>
/// <param name="_data"></param>
void XIOStream::PushBack(const _sp_xdata_type& _data) {
	unique_lock<mutex> lock(mux_);
	datas_.push_back(_data);
	/*��������б�����?*/
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


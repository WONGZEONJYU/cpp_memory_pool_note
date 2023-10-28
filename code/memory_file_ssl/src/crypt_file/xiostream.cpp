#include "xiostream.h"

using namespace std;

/// <summary>
/// �߳�����
/// </summary>
void XIOStream::Start()
{
	th_ = thread(&XIOStream::Main, this);
}

/// <summary>
/// �ȴ��߳��˳�
/// </summary>
void XIOStream::Wait()
{
	if (th_.joinable()) {
		th_.join();
	}
}

void XIOStream::Stop()
{
	is_exit_ = true;
}

void XIOStream::data_byte(const uint64_t n)
{
	data_byte_ = n;
}
	
uint64_t XIOStream::data_byte() const
{
	return data_byte_;
}



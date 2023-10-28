#ifndef XIOSTREAM_H_
#define XIOSTREAM_H_

#include <thread>

class XIOStream
{
	XIOStream(const XIOStream&) = delete;
	XIOStream(XIOStream&&) = delete;
	XIOStream& operator=(const XIOStream&) = delete;
	XIOStream& operator=(XIOStream&&) = delete;

public:
	explicit XIOStream() = default;
	/// <summary>
	/// �߳�����
	/// </summary>
	void Start();

	/// <summary>
	/// �ȴ��߳��˳�
	/// </summary>
	void Wait();

	/// <summary>
	/// �߳��˳�,��Ҫ��Wait�ȴ�
	/// </summary>
	void Stop();

protected:
	/// <summary>
	/// �߳���ں���
	/// </summary>
	virtual void Main() {}

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	constexpr bool is_exit() const noexcept { return is_exit_; };

	/// <summary>
	/// 
	/// </summary>
	/// <param name=""></param>
	void data_byte(uint64_t);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	uint64_t data_byte() const;

private:
	std::thread th_;
	bool is_exit_{};
	uint64_t data_byte_{};
};

#endif

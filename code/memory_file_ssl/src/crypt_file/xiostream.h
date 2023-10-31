#ifndef XIOSTREAM_H_
#define XIOSTREAM_H_

#include <thread>
#include <memory>
#include <memory_resource>

class XIOStream
{
	XIOStream(const XIOStream&) = delete;
	XIOStream(XIOStream&&) = delete;
	XIOStream& operator=(const XIOStream&) = delete;
	XIOStream& operator=(XIOStream&&) = delete;

public:
	using _sp_mrs_type = std::shared_ptr<std::pmr::memory_resource>;
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

	/// <summary>
	/// �����ڴ��
	/// </summary>
	/// <param name=""></param>
	void set_mem_pool(const _sp_mrs_type&);

protected:

	explicit XIOStream() = default;
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
	/// �����ļ���С
	/// </summary>
	/// <param name=""></param>
	void Ass_data_byte(uint64_t);

	/// <summary>
	/// ��ȡ�ļ���С
	/// </summary>
	/// <returns></returns>
	uint64_t xs_data_byte() const;

	_sp_mrs_type mem_pool_;

private:
	std::thread th_;
	bool is_exit_{};
	uint64_t data_byte_{};
};

#endif

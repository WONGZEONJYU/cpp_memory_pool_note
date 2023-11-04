#ifndef XIOSTREAM_H_
#define XIOSTREAM_H_

#include <thread>
#include <memory>
#include <memory_resource>
#include <list>
#include "xdata.h"

class XIOStream
{
	XIOStream(const XIOStream&) = delete;
	XIOStream(XIOStream&&) = delete;
	XIOStream& operator=(const XIOStream&) = delete;
	XIOStream& operator=(XIOStream&&) = delete;

public:
	using _sp_mrs_type = std::shared_ptr<std::pmr::memory_resource>;
	using _sp_xios_type = std::shared_ptr<XIOStream>;
	using _sp_xdata_type = std::shared_ptr<XData>;
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

	/// <summary>
	/// ������������һ���ڵ�
	/// </summary>
	/// <param name="next"></param>
	void set_next(const _sp_xios_type& next);

	/// <summary>
	/// �����󴫵�����,�̰߳�ȫ
	/// </summary>
	/// <param name=""></param>
	void PushBack(const _sp_xdata_type& );
	void PushBack(_sp_xdata_type&&);

protected:

	explicit XIOStream() = default;
	/// <summary>
	/// �߳���ں���
	/// </summary>
	virtual void Main() = 0;

	_sp_xdata_type PopFront();
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	bool is_exit() const noexcept { return is_exit_; };

	/// <summary>
	/// �����ļ���С
	/// </summary>
	/// <param name=""></param>
	void Ass_data_byte(uint64_t);

	/// <summary>
	/// ��ȡ�ļ���С
	/// </summary>
	/// <returns></returns>
	uint64_t data_byte() const;

	/// <summary>
	/// �ڴ��
	/// </summary>
	_sp_mrs_type mem_pool_;

	/// <summary>
	/// ����������
	/// </summary>
	_sp_xios_type next_;

private:
	std::atomic<bool> is_exit_{};
	uint64_t data_byte_{};
	std::thread th_;
	std::list<_sp_xdata_type> datas_;
	std::mutex mux_;
};

#endif

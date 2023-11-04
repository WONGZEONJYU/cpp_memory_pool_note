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
	/// 线程启动
	/// </summary>
	void Start();

	/// <summary>
	/// 等待线程退出
	/// </summary>
	void Wait();

	/// <summary>
	/// 线程退出,需要用Wait等待
	/// </summary>
	void Stop();

	/// <summary>
	/// 设置内存池
	/// </summary>
	/// <param name=""></param>
	void set_mem_pool(const _sp_mrs_type&);

	/// <summary>
	/// 设置责任链下一个节点
	/// </summary>
	/// <param name="next"></param>
	void set_next(const _sp_xios_type& next);

	/// <summary>
	/// 给对象传递数据,线程安全
	/// </summary>
	/// <param name=""></param>
	void PushBack(const _sp_xdata_type& );
	void PushBack(_sp_xdata_type&&);

protected:

	explicit XIOStream() = default;
	/// <summary>
	/// 线程入口函数
	/// </summary>
	virtual void Main() = 0;

	_sp_xdata_type PopFront();
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	bool is_exit() const noexcept { return is_exit_; };

	/// <summary>
	/// 保存文件大小
	/// </summary>
	/// <param name=""></param>
	void Ass_data_byte(uint64_t);

	/// <summary>
	/// 获取文件大小
	/// </summary>
	/// <returns></returns>
	uint64_t data_byte() const;

	/// <summary>
	/// 内存池
	/// </summary>
	_sp_mrs_type mem_pool_;

	/// <summary>
	/// 责任链代码
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

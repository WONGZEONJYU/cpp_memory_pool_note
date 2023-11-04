#ifndef XDATA_H
#define XDATA_H

#include <memory>
#include <memory_resource>

class XData final
{
	explicit XData() = default;
	XData(const XData& ) = delete;
	XData& operator=(const XData&) = delete;

public:
	using _sp_mrs_type = std::shared_ptr<std::pmr::memory_resource>;
	using _sp_xdata_type = std::shared_ptr<XData>;

	XData(XData&& ) noexcept;
	XData& operator=(XData&& ) noexcept;

	/// <summary>
	/// 创建空间
	/// </summary>
	/// <param name="">占用内存字节数</param>
	/// <returns></returns>
	void* New(uint64_t);

	/// <summary>
	/// 设置实际数据字节数
	/// </summary>
	/// <param name=""></param>
	void set_size(const uint64_t s) {size_ = s;}

	/// <summary>
	/// 返回实际数据字节数
	/// </summary>
	/// <returns></returns>
	constexpr auto size() const { return size_; }

	/// <summary>
	/// 返回数据裸指针
	/// </summary>
	/// <returns></returns>
	constexpr auto data() const { return data_; }

	/// <summary>
	/// 是否为数据最后一组数据
	/// </summary>
	/// <returns></returns>
	bool end() const {return end_;}

	/// <summary>
	/// 设置为最后一组数据
	/// </summary>
	/// <param name="e"></param>
	void set_end(const bool e) {end_ = e;}

	/// <summary>
	/// 创建XData智能指针对象
	/// </summary>
	/// <param name="pool"></param>
	/// <returns></returns>
	static _sp_xdata_type Make(const _sp_mrs_type& );

	~XData();

private:
	void _Move(XData&& obj);
	void* data_{};
	std::atomic<bool> end_{};
	uint64_t size_{};/*数据字节数*/
	uint64_t mem_size_{};/*内存空间字节数*/
	_sp_mrs_type mem_pool_;
};

#endif

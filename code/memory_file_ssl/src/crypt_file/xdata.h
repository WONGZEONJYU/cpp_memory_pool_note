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
	/// �����ռ�
	/// </summary>
	/// <param name="">ռ���ڴ��ֽ���</param>
	/// <returns></returns>
	void* New(uint64_t);

	/// <summary>
	/// ����ʵ�������ֽ���
	/// </summary>
	/// <param name=""></param>
	void set_size(const uint64_t s) {size_ = s;}

	/// <summary>
	/// ����ʵ�������ֽ���
	/// </summary>
	/// <returns></returns>
	constexpr auto size() const { return size_; }

	/// <summary>
	/// ����������ָ��
	/// </summary>
	/// <returns></returns>
	constexpr auto data() const { return data_; }

	/// <summary>
	/// �Ƿ�Ϊ�������һ������
	/// </summary>
	/// <returns></returns>
	bool end() const {return end_;}

	/// <summary>
	/// ����Ϊ���һ������
	/// </summary>
	/// <param name="e"></param>
	void set_end(const bool e) {end_ = e;}

	/// <summary>
	/// ����XData����ָ�����
	/// </summary>
	/// <param name="pool"></param>
	/// <returns></returns>
	static _sp_xdata_type Make(const _sp_mrs_type& );

	~XData();

private:
	void _Move(XData&& obj);
	void* data_{};
	std::atomic<bool> end_{};
	uint64_t size_{};/*�����ֽ���*/
	uint64_t mem_size_{};/*�ڴ�ռ��ֽ���*/
	_sp_mrs_type mem_pool_;
};

#endif

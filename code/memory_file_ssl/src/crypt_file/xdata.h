#ifndef XDATA_H
#define XDATA_H

#include <memory>
#include <memory_resource>

class XData final
{
	explicit XData() = default;
	XData(const XData& ) = delete;
	XData(XData&&) = delete;
	XData& operator=(const XData&) = delete;
	XData& operator=(XData&&) = delete;
	
public:
	using _sp_mrs_type = std::shared_ptr<std::pmr::memory_resource>;
	using _sp_xdata_type = std::shared_ptr<XData>;
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
	void set_size(const uint64_t s) {
		size_ = s;
	}

	/// <summary>
	/// ����XData����ָ�����
	/// </summary>
	/// <param name="pool"></param>
	/// <returns></returns>
	static _sp_xdata_type Make(const _sp_mrs_type& );

	~XData();

private:
	void* data_{};
	uint64_t size_{};/*�����ֽ���*/
	uint64_t mem_size_{};/*ռ�ÿռ��ֽ���*/
	_sp_mrs_type mem_pool_;
};

#endif

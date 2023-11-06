#include "xdata.h"
#include <iostream>

using namespace std;
using namespace pmr;

/// <summary>
/// ����XData����ָ�����
/// </summary>
/// <param name="pool"></param>
/// <returns></returns>
XData::_sp_xdata_type XData::Make(const _sp_mrs_type& pool)
{
	_sp_xdata_type ptr{ new XData() };
	ptr->mem_pool_ = pool;
	//cout << "+" << flush;
	return ptr;
}

XData::XData(XData&& obj) noexcept
{
	cout << __FUNCTION__ << flush;
	_Move(std::move(obj));
}

XData& XData::operator=(XData&& obj) noexcept
{
	cout << __FUNCTION__ << flush;
	if (this!= addressof(obj)){
		_Move(std::move(obj));
	}
	return *this;
}

/// <summary>
/// �����ռ�
/// </summary>
/// <param name="">ռ���ڴ��ֽ���</param>
/// <returns></returns>
void* XData::New(const uint64_t mem_size)
{
	if (mem_size <= 0){
		cerr << __FUNCTION__ << " failed! mem_size <=0\n";
		return {};
	}

	if (!mem_pool_){
		cerr << __FUNCTION__ << " failed! mem_pool Uninitialized\n";
		return {};
	}

	data_ = mem_pool_->allocate(static_cast<size_t>(mem_size));
	mem_size_ = data_ ? mem_size : 0;
	size_ = data_ ? mem_size : 0;
	return data_;
}

XData::~XData()
{
	const auto is_{ ((!data_) || (!mem_pool_)) };

	if (is_){
		return;
	}
	mem_pool_->deallocate(data_, static_cast<uint32_t>(mem_size_));
	data_ = nullptr;
	size_ = 0;
	//cout << "-" << flush;
}

void XData::_Move(XData&& obj)
{
	end_.store(obj.end_);
	data_ = obj.data_;
	size_ = obj.size_;
	mem_size_ = obj.mem_size_;
	mem_pool_ = move(obj.mem_pool_);
	
	obj.end_ = false;
	obj.data_ = nullptr;
	obj.size_ = 0;
	obj.mem_size_ = 0;
}

#include "xdata.h"
#include <iostream>

using namespace std;
using namespace pmr;

/// <summary>
/// 创建XData智能指针对象
/// </summary>
/// <param name="pool"></param>
/// <returns></returns>
XData::_sp_xdata_type XData::Make(const _sp_mrs_type& pool)
{
	_sp_xdata_type ptr{ new XData() };
	ptr->mem_pool_ = pool;
	return ptr;
}

/// <summary>
/// 创建空间
/// </summary>
/// <param name="">占用内存字节数</param>
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

	data_ = mem_pool_->allocate(mem_size);
	mem_size_ = mem_size_;
	size_ = mem_size_;
	return data_;
}

XData::~XData()
{
	const auto is_{ ((!data_) || (!mem_pool_)) };

	if (is_){
		return;
	}

	mem_pool_->deallocate(data_, mem_size_);
	data_ = nullptr;
	size_ = 0;
}



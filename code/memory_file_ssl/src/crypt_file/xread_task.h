#ifndef XREA_DTASK_H_
#define XREA_DTASK_H_

#include "xiostream.h"
#include <fstream>

class XReadTask : public XIOStream
{
public:
	explicit XReadTask() = default;
	/// <summary>
	/// 初始化读取线程,获取文件大小
	/// </summary>
	/// <param name="filename"></param>
	/// <returns></returns>
	void Init(std::string filename) noexcept(false);

private:
	/// <summary>
	/// 线程入口函数
	/// </summary>
	void Main() override;
	std::ifstream ifs_;

};

#endif

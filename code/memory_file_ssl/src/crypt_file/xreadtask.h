#ifndef XREADTASK_H_
#define XREADTASK_H_

#include "xiostream.h"
#include <string>
#include <fstream>

class XReadTask : public XIOStream
{
public:
	/// <summary>
	/// 初始化读取线程,获取文件大小
	/// </summary>
	/// <param name="filename"></param>
	/// <returns></returns>
	bool Init(std::string filename);


private:
	/// <summary>
	/// 线程入口函数
	/// </summary>
	void Main() override;
	std::ifstream ifs_;
};

#endif
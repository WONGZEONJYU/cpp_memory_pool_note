#ifndef XREADTASK_H_
#define XREADTASK_H_

#include "xiostream.h"
#include <string>
#include <fstream>

class XReadTask : public XIOStream
{
public:
	/// <summary>
	/// ��ʼ����ȡ�߳�,��ȡ�ļ���С
	/// </summary>
	/// <param name="filename"></param>
	/// <returns></returns>
	bool Init(std::string filename);


private:
	/// <summary>
	/// �߳���ں���
	/// </summary>
	void Main() override;
	std::ifstream ifs_;
};

#endif
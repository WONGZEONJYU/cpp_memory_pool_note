#ifndef XREA_DTASK_H_
#define XREA_DTASK_H_

#include "xiostream.h"
#include <fstream>

class XReadTask : public XIOStream
{
public:
	explicit XReadTask() = default;
	explicit XReadTask(std::string filename);
	/// <summary>
	/// ��ʼ����ȡ�߳�,��ȡ�ļ���С
	/// </summary>
	/// <param name="filename"></param>
	/// <returns></returns>
	bool Init(std::string filename) ;

private:
	/// <summary>
	/// �߳���ں���
	/// </summary>
	void Main() override;
	std::ifstream ifs_;
};

#endif
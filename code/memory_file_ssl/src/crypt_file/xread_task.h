#ifndef XREA_DTASK_H_
#define XREA_DTASK_H_

#include "xiostream.h"
#include <fstream>

class XReadTask : public XIOStream
{
public:
	explicit XReadTask() = default;
	/// <summary>
	/// ��ʼ����ȡ�߳�,��ȡ�ļ���С
	/// </summary>
	/// <param name="filename"></param>
	/// <returns></returns>
	void Init(std::string filename) noexcept(false);

private:
	/// <summary>
	/// �߳���ں���
	/// </summary>
	void Main() override;
	std::ifstream ifs_;

};

#endif

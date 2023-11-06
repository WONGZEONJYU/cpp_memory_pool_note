#ifndef XWRITE_TASK_H_
#define XWRITE_TASK_H_

#include <fstream>
#include "xiostream.h"

class XWriteTask : public XIOStream
{
public:
	explicit XWriteTask() = default;
	void Init(std::string filename) noexcept(false);

private:
	void Main() override;
	std::ofstream ofs_;
	std::string filename_;
};

#endif

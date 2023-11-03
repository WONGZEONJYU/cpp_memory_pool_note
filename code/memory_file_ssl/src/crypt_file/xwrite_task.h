#ifndef XWRITE_TASK_H_
#define XWRITE_TASK_H_

#include <fstream>
#include "xiostream.h"

class XWriteTask : public XIOStream
{
public:
	explicit XWriteTask() = default;
	explicit XWriteTask(std::string filename);
	bool Init(std::string filename);

private:
	void Main() override;
	std::ofstream ofs_;
};

#endif

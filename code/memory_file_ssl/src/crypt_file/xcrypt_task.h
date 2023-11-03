#ifndef XCRYPT_TASK_H
#define XCRYPT_TASK_H

#include "xiostream.h"
class XCrypt;

class XCryptTask: public XIOStream
{
public:
	using _sp_XCrypt_type = std::shared_ptr<XCrypt>;
	explicit XCryptTask() = default;
	explicit XCryptTask(std::string password);
	void Init(std::string password);

private:
	void Main() override;
	_sp_XCrypt_type enc_;
};

#endif 

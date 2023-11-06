#ifndef XCRYPT_TASK_H
#define XCRYPT_TASK_H

#include "xiostream.h"

class XCrypt;

class XCryptTask: public XIOStream
{
public:
	using _sp_XCrypt_type = std::shared_ptr<XCrypt>;
	explicit XCryptTask() = default;
	void Init(std::string password, bool = true) noexcept(false);
	void set_is_encrypt(const bool b = true) { is_encrypt_ = b; }

private:
	void Main() override;
	_sp_XCrypt_type enc_;
	std::atomic<bool> is_encrypt_{true};
};

#endif 

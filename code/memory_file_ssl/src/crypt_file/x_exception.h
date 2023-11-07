#ifndef X_EXCEPTION_H
#define X_EXCEPTION_H

#include <exception>
#include <string>

class XException:public std::exception
{
public:
    XException(std::string err_message) noexcept:
        err_message_{ std::move(err_message)} {}

    const char* what() const override {
        return err_message_.c_str();
    }

    virtual ~XException() = default;

private:
	std::string err_message_;
};

#endif

#ifndef X_EXCEPTION_H
#define X_EXCEPTION_H

#include <exception>
#include <string>

class XException : public std::exception
{
public:
    XException(std::string err_message) :err_message_{ err_message } {}

    char const* what() const override{
        return err_message_.c_str();
    }

private:
	std::string err_message_;
};



#endif

#ifndef CRYPT_APPLICATION_H
#define CRYPT_APPLICATION_H

#include <string>
#include "xfile_crypt.h"

class Crypt_Application
{
	static std::string toLower(std::string& str);

public:
	using _sp_list_XFileCrypt = std::list<std::shared_ptr<XFileCrypt>>;
	explicit Crypt_Application() = default;
	explicit Crypt_Application(int, const char**);
	int exec();
private:
	const int argv_;
	const char** argc_;
	_sp_list_XFileCrypt fes_;

};

#endif 

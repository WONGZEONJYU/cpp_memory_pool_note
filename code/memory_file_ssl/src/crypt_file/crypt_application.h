#ifndef CRYPT_APPLICATION_H
#define CRYPT_APPLICATION_H

#include <string>
#include "xfile_crypt.h"
#include <list>

class Crypt_Application
{
	using Crypt_App = Crypt_Application;
	using _list_sp_XFileCrypt = std::list<std::shared_ptr<XFileCrypt>>;
	Crypt_Application(const Crypt_App&) = delete;
	Crypt_Application& operator=(const Crypt_App&) = delete;
	static std::string toLower(std::string& );
	int check_parm(bool&);
public:	
	explicit Crypt_Application() = default;
	explicit Crypt_Application(int, const char**);
	int exec();
private:
	const int argc_;
	const char** const argv_;
	_list_sp_XFileCrypt fes_;
};

#endif 

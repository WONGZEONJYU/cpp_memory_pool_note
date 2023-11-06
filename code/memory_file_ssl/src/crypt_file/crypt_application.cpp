#include "crypt_application.h"
#include <filesystem>
#include <iostream>

using namespace std;
using namespace filesystem;

string Crypt_Application::toLower(std::string& str) {

	std::transform(str.begin(), str.end(), str.begin(),
		[](unsigned char c) {
			return std::tolower(c);
		});

	return str;
}

Crypt_Application::Crypt_Application(const int argv, const char** argc):
	argv_(argv), argc_(argc)
{
}

int Crypt_Application::exec()
{
	if (argv_ < 5){
		cerr << "parm miss!\n";
		return -1;
	}

	string in_file(argc_[1]), out_file(argc_[2]),
		password(argc_[3]), parm(argc_[4]);

	toLower(parm);

	create_directory(out_file);

	auto is_encrpyt{ true };

	if (!parm.compare("-e")) {
		//is_encrpyt = true;
	}
	else if (!parm.compare("-d")) {
		is_encrpyt = false;
	}
	else {
		cerr << __LINE__ << "parm error!\n";
		(void)getchar();
		return -1;
	}




	return 0;
}



#include "crypt_application.h"
#include <filesystem>
#include <iostream>
#include <memory>

using namespace std;
using namespace filesystem;

string Crypt_Application::toLower(std::string& str) {

	std::transform(str.begin(), str.end(), str.begin(),
		[](unsigned char c) {
			return std::tolower(c);
		});
	return str;
}

Crypt_Application::Crypt_Application(const int argc, const char** argv):
	argc_(argc), argv_(argv)
{
}

int Crypt_Application::exec()
{
	if (argc_ < 5){
		cerr << "parm miss!\n";
		return -1;
	}

	string in_file(argv_[1]), out_file(argv_[2]),
		password(argv_[3]), parm(argv_[4]);

	toLower(parm);

	create_directory(out_file);

	auto is_encrpyt{ true };

	if (!parm.compare("-e")) {
		is_encrpyt = true;
	}else if (!parm.compare("-d")) {
		is_encrpyt = false;
	}else {
		cerr << __LINE__ << "parm error!\n";
		(void)getchar();
		return -1;
	}

	for (auto& p : directory_iterator(in_file)) {

		if (!p.is_regular_file()) { /*只处理文件*/
			continue;
		}

		auto fe{ make_shared<XFileCrypt>() };

		auto src{ p.path().string() };
		auto dst{ out_file + "/" + p.path().filename().string() };

		fe->Init(move(src), move(dst),password, is_encrpyt);

		fes_.push_back(fe);
		fe->Start();
	}
	
	for (auto& fe : fes_) {
		fe->Wait();
	}

	return 0;
}



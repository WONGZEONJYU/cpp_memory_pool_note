#include "crypt_application.h"
#include <filesystem>
#include <iostream>
#include <memory>

using namespace std;
using namespace filesystem;

string Crypt_Application::toLower(std::string& str) {

	std::transform(str.begin(), str.end(), str.begin(),
		[](int c) {
			return std::tolower(c);
		});
	return str;
}

int Crypt_Application::check_parm(bool& b)
{
	if (argc_ < 5) {
		cerr << "parm miss!\n";
		return -1;
	}

	string parm(argv_[4]);
	toLower(parm);

	if (parm == "-e") {
		b = true;
	}else if (parm == "-d") {
		b = false;
	}else {
		cerr << __LINE__ << "parm error!\n";
		return -1;
	}

	return 0;
}

Crypt_Application::Crypt_Application(const int argc, const char** const argv):
	argc_(argc), argv_(argv)
{
}

int Crypt_Application::exec()
{
	auto is_encrpyt{ true };

	if (const auto r{ check_parm(is_encrpyt) }) {
		return r;
	}

	const string in_file(argv_[1]), out_file(argv_[2]),
		password(argv_[3]);

	create_directory(out_file);

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

#include <iostream>
#include <memory>
#include <filesystem>
#include "xcrypt.h"
#include "xfile_crypt.h"

using namespace std;
using namespace filesystem;

//static inline void XCrypt_t();

static std::string toLower(std::string& str) {

	std::transform(str.begin(), str.end(), str.begin(),
		[](unsigned char c) {
			return std::tolower(c);
		});

	return str;
}

int main(int argc, char* argv[])
{
	/*加密指令 输入文件 输出文件 密码 参数 -e*/
	/*解密指令 输入文件 输出文件 密码 参数 -d*/

	if (argc < 5){
		cerr << __LINE__ << "parm miss!\n";
		(void)getchar();
		return -1;
	}

	string in_file(argv[1]), out_file(argv[2]),
		password(argv[3]),parm(argv[4]);

	toLower(parm);

	create_directory(out_file);

	auto is_encrpyt{ true };

	if (!parm.compare("-e")) {
		//is_encrpyt = true;
	}else if (!parm.compare("-d")){
		is_encrpyt = false;
	}else{
		cerr << __LINE__ <<"parm error input -e or -d!\n";
		return -1;
	}

	list<shared_ptr<XFileCrypt>> fes;

	for (auto& p : directory_iterator(in_file)) {

		if (!p.is_regular_file()) { /*只处理文件*/
			continue;
		}

		auto fe{ make_shared<XFileCrypt>() };

		auto out_f{ out_file + "\\" + p.path().filename().string() };

		fe->Init(p.path().string(), move(out_f),
			password, is_encrpyt);

		fes.push_back(fe);
		fe->Start();
	}

	for (auto &fe : fes){
		fe->Wait();
	}

	getchar();
	return 0;
}

static void Single_file_test()
{
	const std::string password("12345678");

	auto xfc{ make_shared<XFileCrypt>() };

	xfc->Init("../../bin/x86/img/test.txt",
		"../../bin/x86/en_test.txt",
		password);

	xfc->Start();
	xfc->Wait();

	auto xfd{ make_shared<XFileCrypt>() };

	xfd->Init("../../bin/x86/en_test.txt",
		"../../bin/x86/de_test.txt",
		password, false);

	xfd->Start();
	xfd->Wait();

}

static inline void XCrypt_t()
{
	XCrypt crypt;
	crypt.Init("12345678");

	{
		cout << "====================1 begin======================\n";

		char out[1024]{};
		auto en_size{ crypt.Encrypt("abcdefghijklmn",24, out,true) };/*8的倍数*/
		cout << "en_size = " << en_size <<
			"\nAfter encryption : " << out << "\n";

		char de_out[1024]{};
		auto de_size{ crypt.Decrypt(out, en_size,de_out, true) };
		cout << "de_size = " << de_size <<
			"\nde_out : " << de_out << "\n";

		cout << "=====================1 end=======================\n\n";
	}

	{
		cout << "====================2 begin======================\n";
		char out[1024]{};
		auto en_size{ crypt.Encrypt("abcdefgh",8, out,true) };
		cout << "en_size = " << en_size << "\nAfter encryption : " <<
			out << "\n";

		char de_out[1024]{};
		auto de_size{ crypt.Decrypt(out, en_size,de_out, true) };
		cout << "de_size = " << de_size <<
			"\nde_out : " << de_out << "\n";
		cout << "=====================2 end=======================\n\n";
	}

	{
		cout << "====================3 begin======================\n";
		char out[1024]{};
		auto en_size = crypt.Encrypt("abcdefghi", 9, out, true);
		cout << "en_size = " << en_size <<
			"\nAfter encryption : " << out << "\n";

		char de_out[1024]{};
		auto de_size{ crypt.Decrypt(out, en_size,de_out, true) };
		cout << "de_size = " << de_size <<
			"\nde_out : " << de_out << "\n";
		cout << "=====================3 end=======================\n\n";
	}
}


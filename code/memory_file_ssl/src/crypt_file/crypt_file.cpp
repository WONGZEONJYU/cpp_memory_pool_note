#include <iostream>
#include "crypt_application.h"
#include "xcrypt.h"

using namespace std;
//static inline void XCrypt_t();

int main(int argc,const char* argv[])
{
	/*加密指令 输入文件 输出文件 密码 参数 -e*/
	/*解密指令 输入文件 输出文件 密码 参数 -d*/

	auto a{ make_shared<Crypt_Application>(argc,argv) };
	const auto r{ a->exec() };
	(void)getchar();
	return r;
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


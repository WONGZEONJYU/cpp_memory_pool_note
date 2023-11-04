#include <iostream>
#include <memory>
#include <memory_resource>
#include "xcrypt.h"
#include "xreadtask.h"
#include "xcrypt_task.h"
#include "xwrite_task.h"

using namespace std;
using namespace pmr;
//static inline void XCrypt_t();

int main(int argc, char* argv[])
{
	std::string password("12345678");

	{
		/*创建内存池*/
		auto mp{ make_shared<synchronized_pool_resource>() };

		/*创建IO读线程*/
		auto rt{ make_shared<XReadTask>("../../bin/x86/img/test.png") };
		//rt->Init("../../bin/x86/img/test.png");
		rt->set_mem_pool(mp);

		/*创建解密线程*/
		auto ct{ make_shared<XCryptTask>(password) };
		//ct->Init(password);
		ct->set_mem_pool(mp);

		/*设置下一责任链*/
		rt->set_next(ct);

		/*创建IO写线程*/
		auto wt{ make_shared<XWriteTask>("../../bin/x86/en_test_out.png") };
		wt->set_mem_pool(mp);

		/*设置下一责任链*/
		ct->set_next(wt);

		rt->Start();
		ct->Start();
		wt->Start();

		rt->Wait();
		ct->Wait();
		wt->Wait();
	}

	{
		/*创建内存池*/
		auto mp{ make_shared<synchronized_pool_resource>() };

		/*创建IO读线程*/
		auto rt{ make_shared<XReadTask>("../../bin/x86/en_test_out.png") };
		//rt->Init("../../bin/x86/img/test.png");
		rt->set_mem_pool(mp);

		/*创建解密线程*/
		auto ct{ make_shared<XCryptTask>(password,false) };
		//ct->Init(password);
		ct->set_mem_pool(mp);

		/*设置下一责任链*/
		rt->set_next(ct);

		/*创建IO写线程*/
		auto wt{ make_shared<XWriteTask>("../../bin/x86/de_test_out.png") };
		wt->set_mem_pool(mp);

		/*设置下一责任链*/
		ct->set_next(wt);

		rt->Start();
		ct->Start();
		wt->Start();

		rt->Wait();
		ct->Wait();
		wt->Wait();
	}

	(void)getchar();
	return 0;
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


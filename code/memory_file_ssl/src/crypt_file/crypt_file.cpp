#include <iostream>
#include <memory>
#include <memory_resource>
#include "xcrypt.h"
#include "xreadtask.h"
#include <mutex>

using namespace std;
using namespace pmr;
static inline void XCrypt_t();

static mutex mux;

int main(int argc, char* argv[])
{
	pool_options opt;

	auto mp{make_shared<synchronized_pool_resource>(opt)};
	//XReadTask::_sp_mrs_type mp{new synchronized_pool_resource ()};
	unique_lock<mutex> lock;
	XReadTask rt;
	rt.Init("../../bin/x86/img/test.png");
	rt.set_mem_pool(mp);
	rt.Start();
	rt.Wait();

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
		auto en_size{ crypt.Encrypt("abcdefghijklmn",24, out,true) };/*8µÄ±¶Êý*/
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


#include "xcrypt_task.h"
#include <iostream>

using namespace std;
using namespace chrono;
using namespace this_thread;

void XCryptTask::Main()
{
	cout << "begin " << __FUNCTION__ << "\n";

	while (!is_exit()){

		auto data{ PopFront() };
		if (!data){
			sleep_for(milliseconds(10));
			cout << "== " << flush;
			continue;
		}
		cout << "<" << data->size() << ">" << flush;
	}
	cout << "end " << __FUNCTION__ << "\n";
}


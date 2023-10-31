#include "xreadtask.h"
#include <iostream>
#include <thread>
#include <memory_resource>
#include "xdata.h"

using namespace std;
using namespace chrono;
using namespace this_thread;

/// <summary>
/// 初始化读取线程,获取文件大小
/// </summary>
/// <param name="filename"></param>
/// <returns></returns>
bool XReadTask::Init(string filename)
{
	if (filename.empty()){
		return false;
	}
	
	ifs_.open(filename, ios::binary);

	if (!ifs_){
		cerr << "open file " << filename << " failed!\n";
		return false;
	}

	cout << "open succcess!\n";

	ifs_.seekg(0, ios::end);/*Move to end of file*/

	Ass_data_byte(ifs_.tellg());

	ifs_.seekg(0, ios::beg); /*Move to beginning of file*/

	cout << " file size = " << xs_data_byte() << "\n";

	return true;
}

void XReadTask::Main()
{
	cout << "begin " << __FUNCTION__ << "\n";
	while (!is_exit()){
		if (ifs_.eof()){
			break;
		}

		char buf[1024 * 10]{};



		ifs_.read(buf, sizeof(buf));
		cout << "[" << ifs_.gcount() << "] " << flush;

	}
	cout << "\nend " << __FUNCTION__ << "\n";
}

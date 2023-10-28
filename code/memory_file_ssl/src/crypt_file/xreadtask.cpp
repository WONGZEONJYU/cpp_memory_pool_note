#include "xreadtask.h"
#include <iostream>
#include <thread>

using namespace std;
using namespace chrono;
using namespace this_thread;

/// <summary>
/// 初始化读取线程,获取文件大小
/// </summary>
/// <param name="filename"></param>
/// <returns></returns>
bool XReadTask::Init(std::string filename)
{
	if (filename.empty()){
		return false;
	}

	ifs_.open(filename, ios::binary);

	if (!ifs_){
		cerr << "open file " << filename << "failed!\n";
		return false;
	}

	cout << "open succcess!\n";

	ifs_.seekg(0, ios::end);

	return true;
}

void XReadTask::Main()
{
	while (!is_exit()){
		sleep_for(milliseconds(1));
	}
}

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

	Ass_data_byte(ifs_.tellg()); /*获取文件大小,存放在XIOStream data_byte_成员*/

	ifs_.seekg(0, ios::beg); /*Move to beginning of file*/

	cout << "file size = " << xs_data_byte() << "\n";

	return true;
}

void XReadTask::Main()
{
	cout << "begin " << __FUNCTION__ << "\n";

	while (!is_exit()){

		if (ifs_.eof()){
			break;
		}

		auto data{ XData::Make(mem_pool_) };

		constexpr auto _mem_size{ 1024 };

		auto buf { data->New(_mem_size) };

		ifs_.read(static_cast<char*>(buf), _mem_size);

		const auto t_size { ifs_.gcount() };

		if (t_size <= 0) {
			break;
		}

		data->set_size(t_size);

		if (ifs_.eof()) {
			data->set_end(true);
		}

		//cout << "[" << t_size << "] " << flush;

		if (next_) {	/*读取完成,数据传递给下一责任链*/
			next_->PushBack(data);
		}
	}

	cout << "\nend " << __FUNCTION__ << "\n";
}


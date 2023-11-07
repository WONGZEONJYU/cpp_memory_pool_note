#include "xread_task.h"
#include <iostream>
#include <thread>
#include <memory_resource>
#include "x_exception.h"
#include "xdata.h"

using namespace std;
using namespace chrono;
using namespace this_thread;

/// <summary>
/// 初始化读取线程,获取文件大小
/// </summary>
/// <param name="filename"></param>
/// <returns></returns>
void XReadTask::Init(string filename) noexcept(false)
{
	if (filename.empty()){
		throw XException(move(string(__FUNCTION__) + " filename is empty!\n"));
	}
	
	ifs_.close();
	ifs_.open(filename, ios::binary);

	if (!ifs_){
		throw XException(move(string(__FUNCTION__) + " open file : " + filename + " failed!\n"));
	}

	cout << filename << " open succcess!\n";

	ifs_.seekg(0, ios::end);/*Move to end of file*/

	Ass_data_byte(ifs_.tellg()); /*获取文件大小,存放在XIOStream data_byte_成员*/

	ifs_.seekg(0, ios::beg); /*Move to beginning of file*/

	cout << "file size = " << data_byte() << "\n";
}

void XReadTask::Main()
{
	cout << "begin " << __FUNCTION__ << "\n";

	while (!is_exit()){

		if (ifs_.eof()){
			break;
		}

		auto data{ XData::Make(mem_pool_) };

		constexpr auto t_mem_size{ 1024 };

		auto buf { data->New(t_mem_size) };

		ifs_.read(static_cast<char*>(buf), t_mem_size);

		const auto t_size { ifs_.gcount() };

		if (t_size <= 0) {
			break;
		}

		data->set_size(t_size);

		if (ifs_.eof()) {
			data->set_end(true);
		}

		if (next_) {	/*读取完成,数据传递给下一责任链*/
			next_->PushBack(move(data));
		}

		//cout << "{" << t_size << "} " << flush;
	}

	ifs_.close();
	cout << "\nend " << __FUNCTION__ << "\n";
}


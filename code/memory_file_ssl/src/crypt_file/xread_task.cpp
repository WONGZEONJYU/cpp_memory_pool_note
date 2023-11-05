#include "xread_task.h"
#include <iostream>
#include <thread>
#include <memory_resource>
#include <exception>
#include "xdata.h"

using namespace std;
using namespace chrono;
using namespace this_thread;

XReadTask::XReadTask(string filename)
{
	Init(move(filename));
}

/// <summary>
/// ��ʼ����ȡ�߳�,��ȡ�ļ���С
/// </summary>
/// <param name="filename"></param>
/// <returns></returns>
bool XReadTask::Init(string filename)
{
	if (filename.empty()){
		return false;
	}
	
	ifs_.close();
	ifs_.open(filename, ios::binary);

	if (!ifs_){
		const auto err{ "open file " + filename + " failed!\n" };
		cerr << err;
		throw exception(err.c_str());
		return false;
	}

	cout << filename <<" open succcess!\n";

	ifs_.seekg(0, ios::end);/*Move to end of file*/

	Ass_data_byte(ifs_.tellg()); /*��ȡ�ļ���С,�����XIOStream data_byte_��Ա*/

	ifs_.seekg(0, ios::beg); /*Move to beginning of file*/

	cout << "file size = " << data_byte() << "\n";

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

		if (next_) {	/*��ȡ���,���ݴ��ݸ���һ������*/
			next_->PushBack(move(data));
		}

		//cout << "{" << t_size << "} " << flush;
	}

	ifs_.close();
	cout << "\nend " << __FUNCTION__ << "\n";
}

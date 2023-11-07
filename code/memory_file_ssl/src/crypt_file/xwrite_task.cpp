#include "xwrite_task.h"
#include <iostream>
#include "x_exception.h"

using namespace std;
using namespace chrono;
using namespace this_thread;

void XWriteTask::Init(string filename) noexcept(false)
{
	if (filename.empty()) {
		throw XException(move(string(__FUNCTION__) + "filename is empty!\n"));
	}

	ofs_.close();
	ofs_.open(filename, ios::binary);

	if (!ofs_){
		throw XException(move(string(__FUNCTION__) + " open file " + filename + " failed!\n"));
	}

	cout << filename << " open success!\n";

	filename_ = move(filename);
}

void XWriteTask::Main()
{
	cout << "begin " << __FUNCTION__ << "\n";
	uint64_t total{};
	while (!is_exit()) {

		const auto src_data{ PopFront() };

		//if (!src_data) {
		//	cout << __FUNCTION__ << " src_data is empty\n" << flush;
		//	sleep_for(milliseconds(10));
		//	continue;
		//}

		const auto t_size{ src_data->size() };
		const auto dst{ static_cast<const char*>(src_data->data())};

		ofs_.write(dst, t_size);
		total += t_size;
		if (src_data->end()){
			cout << filename_ << " size = " << total << "\n"
				<< "Write " << filename_ << " Finish\n";
			break;
		}
	}

	ofs_.close();
	cout << "end " << __FUNCTION__ << "\n";
}


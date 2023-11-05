#include "xwrite_task.h"
#include <iostream>
using namespace std;
using namespace chrono;
using namespace this_thread;

XWriteTask::XWriteTask(string filename)
{
	Init(move(filename));
}

bool XWriteTask::Init(string filename)
{
	if (filename.empty()) {
		cerr << "filename empty\n";
		throw;
		return false;
	}

	ofs_.close();
	ofs_.open(filename, ios::binary);

	if (!ofs_){
		cerr << "open file " << filename << " failed!\n";
		return false;
	}

	cout << filename << " open success!\n";
	filename_ = move(filename);
	return true;
}

void XWriteTask::Main()
{
	cout << "begin " << __FUNCTION__ << "\n";
	uint64_t total{};
	while (!is_exit()) {

		const auto src_data{ PopFront() };

		if (!src_data) {
			cout << __FUNCTION__ << " src_data is empty\n" << flush;
			sleep_for(milliseconds(10));
			continue;
		}

		const auto t_size{ src_data->size() };
		ofs_.write(static_cast<const char*>(src_data->data()), t_size);
		total += t_size;
		if (src_data->end()){
			cout << filename_ << " size = " << total << "\n";
			break;
		}
	}

	ofs_.close();
	cout << "end " << __FUNCTION__ << "\n";
}


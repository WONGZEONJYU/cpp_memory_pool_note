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
		return false;
	}

	ofs_.close();
	ofs_.open(filename, ios::binary);

	if (!ofs_){
		cerr << "open file " << filename << " failed!\n";
		return false;
	}

	cout << filename << " open success!\n";

	return true;
}

void XWriteTask::Main()
{
	cout << "begin " << __FUNCTION__ << "\n";

	while (!is_exit()) {

		auto src_data{ PopFront() };

		if (!src_data) {
			sleep_for(milliseconds(10));
			continue;
		}

		//auto dst_data {XData::Make()};
		ofs_.write(static_cast<const char*>(src_data->data()), src_data->size());

		if (src_data->end()){
			break;
		}
	}

	ofs_.close();
	cout << "end " << __FUNCTION__ << "\n";
}


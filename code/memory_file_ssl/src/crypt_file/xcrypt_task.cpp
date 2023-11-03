#include "xcrypt_task.h"
#include <iostream>
#include "xcrypt.h"

using namespace std;
using namespace chrono;
using namespace this_thread;

XCryptTask::XCryptTask(std::string password)
{
	Init(move(password));
}

void XCryptTask::Init(std::string password)
{
	enc_ = make_shared<XCrypt>(move(password));
}

void XCryptTask::Main()
{
	cout << "begin " << __FUNCTION__ << "\n";

	while (!is_exit()){

		auto data{ PopFront() };

		if (!data){
			sleep_for(milliseconds(10));
			//cout << "== " << flush;
			continue;
		}

		auto out{ XData::Make(mem_pool_) };

		/*源文件大小*/
		const auto src_data_size{ data->size() };

		/*补位后的文件大小*/
		const auto outsize{ src_data_size + enc_->Getpadding(src_data_size)};

		out->New(outsize);

		auto dst_data_size { enc_->Encrypt(static_cast<const char*>(data->data()), src_data_size,
			static_cast<char*>(out->data()))};

		out->set_size(dst_data_size);

		//cout << "<" << out->size() << ">" << flush;
		out->set_end(data->end());

		if (next_){
			next_->PushBack(out);
		}

		if (data->end()){
			break;
		}
	}

	cout << "end " << __FUNCTION__ << "\n";
}

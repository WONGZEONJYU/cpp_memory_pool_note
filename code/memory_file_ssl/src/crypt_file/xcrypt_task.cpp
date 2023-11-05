#include "xcrypt_task.h"
#include <iostream>
#include "xcrypt.h"

using namespace std;
using namespace chrono;
using namespace this_thread;

XCryptTask::XCryptTask(string password , const bool b) :
	enc_{ move(make_shared<XCrypt>(move(password)))}, is_encrypt_{move(b)}
{
}

void XCryptTask::Init(string password)
{
	enc_ = move(make_shared<XCrypt>(move(password)));
}

void XCryptTask::Main()
{
	cout << "begin " << __FUNCTION__ << "\n";

	while (!is_exit()){

		auto src_data { PopFront() };

		if (!src_data) {
			cout << __FUNCTION__ << " src_data is empty\n" << flush;
			sleep_for(milliseconds(10));
			continue;
		}

		auto out_data { XData::Make(mem_pool_) };

		/*源文件大小*/
		const auto src_data_size{ src_data->size() };

		/*补位后的文件大小*/
		const auto outsize{ src_data_size + enc_->Getpadding(src_data_size)};

		auto dst { out_data->New(outsize) };

		size_t dst_data_size {};

		const auto is_end { src_data->end() };

		if (is_encrypt_) {
			dst_data_size = { enc_->Encrypt(static_cast<const char*>(src_data->data()), 
						src_data_size,static_cast<char*>(dst),is_end) };
		}else {
			dst_data_size = { enc_->Decrypt(static_cast<const char*>(src_data->data()),
						src_data_size,static_cast<char*>(dst),is_end) };
		}

		out_data->set_size(dst_data_size);
		out_data->set_end(is_end);

		//cout << "<" << out_data->size() << ">" << flush;

		if (next_){
			next_->PushBack(move(out_data));
		}

		if (is_end){
			break;
		}
	}

	cout << "\nend " << __FUNCTION__ << "\n";
}

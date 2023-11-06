#include "xfile_crypt.h"
#include "xread_task.h"
#include "xcrypt_task.h"
#include "xwrite_task.h"
#include <iostream>
#include "x_exception.h"
using namespace std;

void XFileCrypt::Init(std::string infile, std::string outfile,
	std::string passwd, const bool is_encrpty) noexcept(false)
{
	/*�����ڴ��*/
	auto mp{ make_shared<pmr::synchronized_pool_resource>() };

	/*����IO���߳�*/
	rt_ = make_shared<XReadTask>();
	rt_->Init(std::move(infile));
	rt_->set_mem_pool(mp);

	/*������/�����߳�*/
	ct_ = make_shared<XCryptTask>();
	ct_->Init(std::move(passwd), is_encrpty);
	ct_->set_mem_pool(mp);

	/*������һ������-->����*/
	rt_->set_next(ct_);

	/*����IOд�߳�*/
	wt_ = make_shared<XWriteTask>();
	wt_->Init(std::move(outfile));

	wt_->set_mem_pool(mp);

	/*������һ������-->д�ļ�*/
	ct_->set_next(wt_);
}

void XFileCrypt::Start() noexcept(false)
{
	if (rt_ && ct_ && wt_) {
		rt_->Start();
		ct_->Start();
		wt_->Start();
	}else{
		throw XException(move(string(__FUNCTION__) + "Please call the init function to initialize\n"));
	}
}

void XFileCrypt::Wait() noexcept(false)
{
	if (rt_ && ct_ && wt_) {
		rt_->Wait();
		ct_->Wait();
		wt_->Wait();
	}else{
		throw XException(move(string(__FUNCTION__) + "Please call the init function to initialize\n"));
	}
}

#include "xfile_crypt.h"
#include "xread_task.h"
#include "xcrypt_task.h"
#include "xwrite_task.h"
#include <iostream>

using namespace std;

XFileCrypt::XFileCrypt(std::string infile, std::string outfile,
	std::string passwd, const bool is_encrpty)
{
	Init(std::move(infile), std::move(outfile),
		std::move(passwd), is_encrpty);
}

bool XFileCrypt::Init(std::string infile, std::string outfile,
	std::string passwd, const bool is_encrpty) 
{
	/*�����ڴ��*/
	auto mp{ make_shared<pmr::synchronized_pool_resource>() };

	/*����IO���߳�*/
	rt_ = make_shared<XReadTask>(std::move(infile));
	rt_->set_mem_pool(mp);

	/*������/�����߳�*/
	ct_ = make_shared<XCryptTask>(std::move(passwd), is_encrpty);
	ct_->set_mem_pool(mp);

	/*������һ������-->����*/
	rt_->set_next(ct_);

	/*����IOд�߳�*/
	wt_ = make_shared<XWriteTask>(std::move(outfile));
	wt_->set_mem_pool(mp);

	/*������һ������-->д�ļ�*/
	ct_->set_next(wt_);

	return true;
}

void XFileCrypt::Start()
{
	if (rt_ && ct_ && wt_) {
		rt_->Start();
		ct_->Start();
		wt_->Start();
	}
}

void XFileCrypt::Wait()
{
	if (rt_ && ct_ && wt_) {
		rt_->Wait();
		ct_->Wait();
		wt_->Wait();
	}
}


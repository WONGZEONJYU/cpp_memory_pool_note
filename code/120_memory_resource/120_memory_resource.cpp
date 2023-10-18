

#include <iostream>
#include <memory_resource>
#include <vector>
#include <thread>
using namespace std;
using namespace pmr;
using namespace chrono;

/*

����������ѡ�� options.max_blocks_per_chunk �� options.largest_required_pool_block�����������������ڴ�صĲ������á�

options.max_blocks_per_chunk����ѡ����������ÿ���ڴ�飨chunk���������ڴ����Ŀ��
�ڴ��ͨ���Ὣ���õ��ڴ滮��Ϊ�ϴ���ڴ�飬Ȼ��ÿ���ڴ���һ������Ϊ��С���ڴ�飬
�Թ��ڴ����ʹ�á�max_blocks_per_chunk ������������ÿ���ڴ���������Ի��ֳ����ٸ���С���ڴ�顣
ͨ�������ڴ���е��ڴ�����������Ե����ڴ�صĹ���ʽ��Ӱ���ڴ��������Ⱥ����ܡ�

options.largest_required_pool_block����ѡ�����������ڴ�����������ڴ���С��
����Ҫ����ϴ���ڴ�ʱ����������С�������ڴ���������ڴ���С��
��ô�ڴ�ؿ����޷���������largest_required_pool_block ����ȷ���ڴ�����������ڴ���С��
�Ա����ڴ����ʱ�����ʵ��Ĵ���͹���

������ѡ��ͨ�����ڴ�ص�������ʹ�ã����ڵ����ڴ�ص����ܺ��ڴ������ԡ�
ͨ���ʵ������� max_blocks_per_chunk �� largest_required_pool_block �����Ż��ڴ�ص������ʡ����������������ڴ����Ч�ʡ�

��ע�⣬�����ѡ�����ƺͶ�����ܻ���ͬ���ڴ��ʵ�ֶ��������졣�����������ĵ���ο����ʹ��˵�����˽��ض��ڴ��ʵ������Щѡ�����ϸ������÷���

					**�ڴ������ǳ�ָ��������**
����:max_blocks_per_chunk ���� 1024 * 1024 * 100 = 100M
��ʼ��֮���ڴ�ش����η����100m
��100M�������֮��,��Ҫ���������ʱ��,�ڴ�ش����μ�������100M,�ַ�����֮��,�ڴ�����ʱ�����������200M,��һ��400M,��һ��800M,��ָ��������

����Զ����С����largest_required_pool_block��С,ÿ�ξͰ����Զ����С����

*/

int main(int argc, char* argv[])
{

	pool_options opt;
	opt.largest_required_pool_block = 1024 * 1024 * 10;	/*�����ݿ���ֽ��� */
	/*10M*/
	opt.max_blocks_per_chunk = 1024 * 1024 * 100;		/*��ͨ����,ÿ�����ݿ�Ĵ�С*/
	/*���һ�����ݿ�������ˣ�����Ҫ��������Ļ�,�ڴ����ȥ����max_blocks_per_chunk������*/
	/*����������ݿ鳬����largest_required_pool_block,����*/
	/*100M*/

	/*�̰߳�ȫ���ڴ��*/
	synchronized_pool_resource mpool(opt);
	std::vector<void*> datas;

	constexpr int size{ 1024 * 1024  }; /*1M*/

	for (int i{}; i < 1024; i++){	/*һ������1G*/
		try {
			/*���ڴ������һ��ռ�*/
			auto data{ mpool.allocate(size) }; /*ÿ������1M*/
			datas.push_back(data);
			cout << "+" << flush;
			this_thread::sleep_for(milliseconds(20));
		}
		catch (const std::exception& ex) {
			cerr << "mpool.allocate failed!" << ex.what() << "\n";
			exit(-1);
		}
	}
	
	auto b1{ mpool.allocate(1024 * 1024 * 20) }; /*������ռ�*/
	mpool.deallocate(b1, 1024 * 1024 * 20);

	for (auto &d : datas) { /*���տռ�*/
		mpool.deallocate(d, size);
		cout << "-" << flush;
		this_thread::sleep_for(milliseconds(20));
	}

	mpool.release(); /*�ͷ��ڴ�������ڴ�*/

	(void)getchar();
	return 0;
}

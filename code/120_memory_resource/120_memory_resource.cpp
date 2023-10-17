

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

*/

int main(int argc, char* argv[])
{
	pool_options opt;
	opt.largest_required_pool_block = 1024 * 1024 * 10;	/*�����ݿ���ֽ��� */
	/**/
	/*10M*/
	opt.max_blocks_per_chunk = 1024 * 1024 * 100;		/*��ͨ����,ÿ�����ݿ�Ĵ�С*/
	/*100M*/

	/*�̰߳�ȫ���ڴ��*/
	synchronized_pool_resource mpool(opt);
	std::vector<void*> datas;

	constexpr int size{ 1024 * 1024 }; /*1M*/

	for (int i{}; i < 2048; i++){
		try {
			/*���ڴ������һ��ռ�*/
			auto data{ mpool.allocate(size) };
			datas.push_back(data);
			cout << "+" << flush;
			this_thread::sleep_for(milliseconds(10));
		}
		catch (const std::exception& ex) {
			cerr << "mpool.allocate failed!" << ex.what() << "\n";
			exit(-1);
		}
	}

	(void)getchar();
	return 0;
}

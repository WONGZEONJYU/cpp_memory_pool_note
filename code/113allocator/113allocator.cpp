#include <iostream>
#include <vector>
#include <list>
#include "MyAllocator.hpp"

using namespace std;

class XData
{
public:
	XData() { cout << __FUNCTION__ << "\n"; }
	~XData() { cout << __FUNCTION__ << " " << index << "\n"; }
	XData(const XData& o) {
		index = o.index; 
		cout << "copy " << __FUNCTION__ << " " << index << "\n";
	}
	int index{};
};

namespace one
{
	void test()
	{
		allocator<XData> xdata_allco;
		constexpr int size{ 3 };

		/*�������ռ� �����ù���*/
		auto dataarr{ xdata_allco.allocate(size) };

		for (size_t i{}; i < size; i++) {

			/*allocator_traits ��ģ���ṩ���ʷ�����(Allocator)�������Եı�׼����ʽ*/

			/*���ù���*/
			allocator_traits<decltype(xdata_allco)>::construct(xdata_allco, dataarr + i);

			/*��������*/
			allocator_traits<decltype(xdata_allco)>::destroy(xdata_allco, dataarr + i);
		}

		/*����ռ� , ����������*/
		xdata_allco.deallocate(dataarr, size);
	}
}

namespace two
{
	void test()
	{
		vector<XData, MyAllocator<XData>> vd;
		XData d;
		d.index = 111;
		vd.push_back(d);
		d.index = 222;
		vd.push_back(d);
		d.index = 333;
		vd.push_back(d);

		for (auto& xd :vd){
			cout << xd.index << '\n';
		}

		cout << "==========================================\n";

		list<XData, MyAllocator<XData>> datas;
		d.index = 444;
		datas.push_back(d);
		d.index = 555;
		datas.push_back(d);
		d.index = 666;
		datas.push_back(d);

		for (auto& d:datas)
		{
			cout << d.index << '\n';
		}
	}
}

int main(int argc, char* argv[])
{
	two::test();
	(void)getchar();
	return 0;
}


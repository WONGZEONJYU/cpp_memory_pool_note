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

		/*分配对象空间 不调用构造*/
		auto dataarr{ xdata_allco.allocate(size) };

		for (size_t i{}; i < size; i++) {

			/*allocator_traits 类模板提供访问分配器(Allocator)各种属性的标准化方式*/

			/*调用构造*/
			allocator_traits<decltype(xdata_allco)>::construct(xdata_allco, dataarr + i);

			/*调用析构*/
			allocator_traits<decltype(xdata_allco)>::destroy(xdata_allco, dataarr + i);
		}

		/*清理空间 , 不调用析构*/
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


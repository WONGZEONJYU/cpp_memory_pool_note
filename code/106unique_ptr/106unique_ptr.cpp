#include <iostream>

using namespace std;

class Data 
{
public:
	static int count;
	int index{};
	Data() {
		index = ++count;
		cout << index << ' ' << __FUNCTION__ << '\n';
	}
	~Data() {
		cout << index << ' ' << __FUNCTION__ << '\n';
	}
};

int Data::count {};

static void _unique_ptr_()
{
	/*RAII 资源获取即初始化 (Resource Acquisition Is Initialization)*/
	{
		unique_ptr<int> p1(new int);
		unique_ptr<Data> p2(new Data);
		cout << "========1=========\n";
		auto p3{ make_unique<Data>() };

		/*空智能指针*/
		unique_ptr<Data> p4;
		unique_ptr<int[]> pa1{ make_unique<int[]>(1024) };
		unique_ptr<int[]> pa2(new int[1024]);
		unique_ptr<Data[]> pa3(new Data[3]);

		/*unique_ptr智能指针访问和移动构造赋值*/
		*p1 = 10;
		cout << "p1 value = " << *p1 << '\n';
		cout << "(*p2).index = " << (*p2).index << '\n';
		cout << "p2->index = " << p2->index << '\n';
		auto d1{ new Data()};
		unique_ptr<Data> p5(d1);
		cout << "p5 address : " << p5 << '\n';
		cout << "d1 address : " << d1 << '\n';
		cout << "p5.get() : " << p5.get() << '\n';
		pa2[0] = 1;
		pa2[1] = 2;
		cout << "pa3[0].index = " << pa3[0].index << '\n';
	}
	cout << "========2=========\n";
}

static void _share_ptr_()
{


}


int main(int argc, char** argv[])
{
	_unique_ptr_();
	//_share_ptr_();
	(void)getchar();
	return 0;
}

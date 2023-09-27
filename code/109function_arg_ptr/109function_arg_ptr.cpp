#include <iostream>
#include <memory>

using namespace std;

namespace _test_1_
{
	void PtrFunction(const char* data, int size)
	{
		cout << "sizeof(data) = " << sizeof(data) << '\n';
	}

	/*经过参数传递 数组转换成指针*/
	void PtrFunction(const char data[])
	{
		cout << "sizeof(data) = " << sizeof(data) << '\n';
	}

	/*传递参数 获取数组大小*/
	template<typename Ty, size_t SIZE>
	void TestMen(Ty(&data)[SIZE])
	{
		cout << "sizeof(data) = " << sizeof(data) << '\n';
	}

	/*指针输出*/
	/*
		1 修改原内存
		2 使用函数内创建的内存
	*/

	char* TestMen()
	{
		/*不能返回栈中空间*/
		char buf[1024]{ "test" };
		return buf;
	}

	void TestMen(char* out)
	{
		/*修改的是局部变量,内存泄露*/
		out = new char[1024];
	}

	/*返回的空间需要注释,由用户释放*/
	int TestMen(char** out)
	{
		int size{ 1024 };
		*out = new char[size];
		return size;
	}

	void test1()
	{
		char data[]{ "test mem ptr" };

		PtrFunction(data, sizeof(data));
		PtrFunction(data);
		TestMen(data);

		/*异常空间已经释放 , 结果不确定*/
		cout << TestMen() << '\n';

		char* out{};
		TestMen(out);

		cout << "out = " << reinterpret_cast<long long>(out) << '\n';
		TestMen(&out);
		cout << "out = " << reinterpret_cast<long long>(out) << '\n';
		delete[] out;
		out = nullptr;
		cout << "\n\n";
	}
}

namespace _test_2_
{
	/*智能指针作为函数参数和返回值*/

	class XData
	{
		//XData(const XData&) = delete;
		//XData& operator=(const XData&) = delete;
	public:
		XData() { cout << __FUNCTION__ << '\n'; }
		~XData() { cout << __FUNCTION__ << '\n'; }
		int index{};
	};

	unique_ptr<XData> TestUnique(unique_ptr<XData> ptr)
	{
		cout << "prt->index = " << ptr->index << '\n';
		unique_ptr<XData> re(new XData);
		re->index = 222;
		/*编译器优化 1 如果返回值支持move 编译器自动调用move,不支持调用拷贝构造*/
		return re;
	}

	void test2()
	{
		unique_ptr<XData> ptr1(new XData);
		ptr1->index = 111;

		cout << "ptr1->index = " << ptr1->index << '\n';
		auto re{ TestUnique(move(ptr1)) };

		cout << "re->index = " << re->index << '\n';

		if (!ptr1) {
			cout << "ptr1 empty\n";
		}
		else {
			cout << "ptr1->index = " << ptr1->index << '\n';
		}
	}
}

int main(int argc, char* argv[])
{
	//_test_1_::test1();

	_test_2_::test2();

	(void)getchar();
	return 0;
}



#include <iostream>
#include <memory>

using namespace std;

namespace _test_1_
{
	void PtrFunction(const char* data, int size)
	{
		cout << "sizeof(data) = " << sizeof(data) << '\n';
	}

	/*������������ ����ת����ָ��*/
	void PtrFunction(const char data[])
	{
		cout << "sizeof(data) = " << sizeof(data) << '\n';
	}

	/*���ݲ��� ��ȡ�����С*/
	template<typename Ty, size_t SIZE>
	void TestMen(Ty(&data)[SIZE])
	{
		cout << "sizeof(data) = " << sizeof(data) << '\n';
	}

	/*ָ�����*/
	/*
		1 �޸�ԭ�ڴ�
		2 ʹ�ú����ڴ������ڴ�
	*/

	char* TestMen()
	{
		/*���ܷ���ջ�пռ�*/
		char buf[1024]{ "test" };
		return buf;
	}

	void TestMen(char* out)
	{
		/*�޸ĵ��Ǿֲ�����,�ڴ�й¶*/
		out = new char[1024];
	}

	/*���صĿռ���Ҫע��,���û��ͷ�*/
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

		/*�쳣�ռ��Ѿ��ͷ� , �����ȷ��*/
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
	/*����ָ����Ϊ���������ͷ���ֵ*/

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
		/*�������Ż� 1 �������ֵ֧��move �������Զ�����move,��֧�ֵ��ÿ�������*/
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



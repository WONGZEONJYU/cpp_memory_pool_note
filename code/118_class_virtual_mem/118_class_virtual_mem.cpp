#include <iostream>
using namespace std;

/*�麯�������*/
class Base
{
public:
	virtual void Test1() { cout << __FUNCTION__ << "\n"; }
	virtual void Test2() { cout << __FUNCTION__ << "\n"; }
	int x1{}, x2{}, x3{};
};

class A : public Base
{
public:
	void Test1() override { cout << __FUNCTION__ << "\n"; }
	void Test2() override { cout << __FUNCTION__ << "\n"; }
	void Test3() { cout << __FUNCTION__ << "\n"; };
};

class C : public Base
{
public:
	void Test1() override  { cout << __FUNCTION__ << "\n"; }
	void Test2() override  { cout << __FUNCTION__ << "\n"; }
};

void TestClass(Base *b)
{
	cout << __FUNCTION__ << "\n";
	b->Test1();
}

int main(int argc, char* argv[])
{
#if 1
	{
		Base b;

		auto vfptable_b{ reinterpret_cast<long long*>(&b) };
		/*�麯����ָ��,ָ���麯���� vfptable_b --> vftable_b[]*/

		auto vftable_b{ reinterpret_cast<long long*>(*vfptable_b) };
		/*�麯����*/

		cout << "b address : \t\t0x" << vfptable_b << "\n";
		cout << "vftable_b address : \t0x" << vftable_b << "\n";

		A a1;
		A a2;

		auto vfptable1{ reinterpret_cast<long long*>(&a1) };
		/*�麯����ָ��,ָ���麯���� vfptable1 --> vftable1[]*/
		auto vftable1{ reinterpret_cast<long long*>(*vfptable1) };

		auto vfptable2{ reinterpret_cast<long long*>(&a2) };
		/*�麯����ָ��,ָ���麯���� vfptable2 --> vftable2[]*/
		auto vftable2{ reinterpret_cast<long long*>(*vfptable2) };

		/*ͬһ����ģ�͵Ĳ�ͬʵ������ , �麯����ָ�� ָ�� ͬһ���麯����*/
		cout << "a1 address : \t\t0x" << vfptable1 << "\n";
		cout << "vftable1 address : \t0x" << vftable1 << "\n";
		
		cout << "a2 address : \t\t0x" << vfptable2 << "\n";
		cout << "vftable2 address : \t0x" << vftable2 << "\n";

		using VFunc = void(*)(void);
		auto test1{ reinterpret_cast<VFunc>(vftable1[0])};
		auto test2{ reinterpret_cast<VFunc>(vftable1[1])};
		test1();
		test2();
	}
#endif

#if 0
	{
		Base b;
		A a;
		TestClass(&a);
		C c;
		TestClass(&c);
	}
#endif
	(void)getchar();
	return 0;
}



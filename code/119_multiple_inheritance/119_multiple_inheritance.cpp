#include <iostream>

using namespace std;

class A
{
public:
	virtual void fA() { cout << __FUNCTION__ << "\n"; }
	virtual void gA() { cout << __FUNCTION__ << "\n"; }
};

class B
{
public:
	virtual void fB() { cout << __FUNCTION__ << "\n"; };
	virtual void gB() { cout << __FUNCTION__ << "\n"; };
};

class C :public A, public B
{
	virtual void fC() { cout << __FUNCTION__ << "\n"; }
	virtual void gC() { cout << __FUNCTION__ << "\n"; }
};

using VFunc = void(*)();
using ll = long long;

int main(int argc, char* argv[])
{
	C c1, c2;
	cout << "===========================c1 begin===========================\n";
	auto vfptable_c1{ reinterpret_cast<ll*>(&c1) };
	auto vftable_c1{ reinterpret_cast<ll*>(vfptable_c1[0]) }; /*指向第一个继承类的虚函数表*/

	cout << "c1 address : \t\t0x" << vfptable_c1 << "\n";
	cout << "vftable_c1 : \t\t0x" << vftable_c1 << "\n";

	auto f1{ reinterpret_cast<VFunc>(vftable_c1[0])};
	auto f2{ reinterpret_cast<VFunc>(vftable_c1[1]) };
	/*以下两个是 类C 本身的虚函数 , 共同放在同一个虚函数表*/
	auto f3{ reinterpret_cast<VFunc>(vftable_c1[2]) };
	auto f4{ reinterpret_cast<VFunc>(vftable_c1[3]) };
	f1();
	f2();
	f3();
	f4();

	auto vftable2_c1{ reinterpret_cast<ll*>(vfptable_c1[1])}; /*指向第二个继承类的虚函数表*/
	cout << "vftable2_c1 : \t\t0x" << vftable2_c1 << "\n";
	f1 = reinterpret_cast<VFunc>(vftable2_c1[0]);
	f2 = reinterpret_cast<VFunc>(vftable2_c1[1]);
	f1();
	f2();

	cout << "=============================c1 end=============================\n\n";

	cout << "===========================c2 begin===========================\n";
	auto vfptable_c2{ reinterpret_cast<ll*>(&c2) };
	auto vftable_c2{ reinterpret_cast<ll*>(vfptable_c2[0])};

	cout << "c2 address : \t\t0x" << vfptable_c2 << "\n";
	cout << "vftable_c2 : \t\t0x" << vftable_c2 << "\n";

	f1 = reinterpret_cast<VFunc>(vftable_c2[0]);
	f2 = reinterpret_cast<VFunc>(vftable_c2[1]);
	f3 = reinterpret_cast<VFunc>(vftable_c2[2]);
	f4 = reinterpret_cast<VFunc>(vftable_c2[3]);
	f1();
	f2();
	f3();
	f4();

	auto vftable2_c2{ reinterpret_cast<ll*>(vfptable_c2[1])};
	cout << "vftable2_c2 : \t\t0x" << vftable2_c2 << "\n";

	f1 = reinterpret_cast<VFunc>(vftable2_c2[0]);
	f2 = reinterpret_cast<VFunc>(vftable2_c2[1]);
	f1();
	f2();
	cout << "=============================c2 end=============================\n\n";

	(void)getchar();
	return 0;
}

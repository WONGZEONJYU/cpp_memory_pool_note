#include <iostream>

using namespace std;

class Base1
{
public:
	virtual void F1() {};
	virtual void F2() {};
};

class Base2
{
public:
	virtual void F1() {};
	virtual void F2() {};
};

class A :public Base1, public Base2
{
public :
	virtual void F1() {};
	virtual void F2() {};
};

int main(int argc, char* argv[])
{

	(void)getchar();
	return 0;
}

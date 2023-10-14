#include <iostream>
using namespace std;

/*
ָ�����������
����ջ�д������� , ���Ƶ��� delete ���ٶ���

*/

class TestMem
{
public:
	static TestMem* Create() {
		cout << __FUNCTION__ << "\n";
		return new TestMem();
	}

	static void Drop(TestMem* tm) { /*destroy*/
		cout << __FUNCTION__ << "\n";
		delete tm;
	}

protected:
	TestMem() {
		cout << __FUNCTION__ << "\n";
	}
	virtual ~TestMem() {
		cout << __FUNCTION__ << "\n";
	}
};

int main(int argc, char* argv[])
{
	//TestMem tm1;
	//auto tm2{ new TestMem() };

	TestMem* tm3{ TestMem::Create() };

	//delete tm3;

	TestMem::Drop(tm3);

	(void)getchar();
	return 0;
}

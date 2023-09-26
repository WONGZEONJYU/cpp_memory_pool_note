#include <iostream>

using namespace std;

class XData
{
public:
	XData() {
		cout << __FUNCTION__ << '\n';
	}
	~XData() {
		cout << __FUNCTION__ << '\n';
	}
	int index1{}, index2{};
};

void DelData(XData* p)
{
	cout << "call " << __FUNCTION__ << '\n';
	delete p;
}

int main(int argc, char* argv[])
{
	{
		/*1.��ʼ��*/
		shared_ptr<int> sp1(new int);
		shared_ptr<int[]> sp2(new int[1024]);
		*sp1 = 10;
		sp2[0] = 100;
		auto d1{ sp1.get() /*sp1.operator->()*/ };/*��ȡ��ָ��*/

		//auto d2{ sp2 .operator->() }; /*operator->()�ú���ģ����int[]���͵������û��ʵ����*/

		auto sp3{ make_shared<XData>() };
		cout << "sp3.use_count() = " << sp3.use_count() << '\n';

		/*2.�ɸ��ƹ����븳ֵ*/
		auto sp4{ sp3 };
		cout << "auto sp4 {sp3}; sp3.use_count() = " << sp3.use_count() << '\n';/*2*/
		cout << "sp4.use_count() = " << sp4.use_count() << '\n';/*2*/
		auto sp5{ make_shared<XData>() };
		sp4 = sp5;
		cout << "sp4 = sp5; sp3.use_count() = " << sp3.use_count() << '\n';/*1*/

		{
			auto sp6 { sp3 };
			cout << "sp6 = sp3; sp3.use_count() = " << sp3.use_count() << '\n';/*2*/
		}

		cout << "exit } sp3.use_count() = " << sp3.use_count() << '\n';/*1*/
		sp3.reset(); /* -1:��һ ������ü���Ϊ 0 �� , ����ռ� */
		cout << "sp3.reset() sp3.use_count() = " << sp3.use_count() << '\n';/*0*/
	}

	cout << "after }\n\n";

	/*3 shared_ptr����ɾ������*/
	{
		shared_ptr<XData> sp7(new XData, DelData);
		shared_ptr<XData> sp8(new XData, [](auto* p) {
			
			cout << "Call delete lambda\n";
			delete p;
		});
	}
	cout << "after delete }\n\n";


	/*4 shared_ptr ����ָ��ָ��ͬһ������ͬ�ĳ�Ա*/
	{
		shared_ptr<XData> sc1(new XData);
		cout << "sc1 use_count = " << sc1.use_count() << '\n';

		shared_ptr<int> sc2(sc1, &sc1->index2);
		shared_ptr<int> sc3(sc1, &sc1->index1);

		cout << "sc1 use_count = " << sc1.use_count() << '\n';
	}

	(void)getchar();
	return 0;
}


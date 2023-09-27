#include <iostream>
#include <memory>

/*
 weak_ptr
	use_count
		���ع���ö����shared_ptr��������
	lock
		�����������õĶ����shared_ptr
*/

using namespace std;

class XData
{
public:
	XData() { cout << __FUNCTION__ << '\n'; }
	~XData(){ cout << __FUNCTION__ << '\n'; }

};

class B;
class A
{
public:
	A() { cout << __FUNCTION__ << '\n'; }
	~A() { cout << __FUNCTION__ << '\n'; }
	void Do() {
		cout << "Do b2.use_count() = " << b2.use_count() << '\n';
		auto b{ b2.lock() }; /*����һ����������ָ�� ����+1*/
		cout << "Do b2.use_count() = " << b2.use_count() << '\n';
		/*�뿪��ǰ������,b2.use_count() -1 = 1*/
	}
	shared_ptr<B> b1;
	weak_ptr<B> b2;
};

class B
{
public:
	B() { cout << __FUNCTION__ << '\n'; }
	~B() { cout << __FUNCTION__ << '\n'; }
	shared_ptr<A> a1;
};

int main(int argc, char* argv[])
{
	{
		auto a{ make_shared<A>() };	/*=1 */
		auto b{ make_shared<B>() };	/*=1 */
		a->b1 = b;	/*+1 =2 */
		cout << "a->b1 = b b.use_count() = " << b.use_count() << '\n';
		b->a1 = a;	/*+1 =2 */
		cout << "b->a1 = a a.use_count() = " << a.use_count() << '\n';
		/*
			a �������� a.use_count() - 1 = 1 a��Դ���ͷ� , a.b1���ͷ�
			b.use_count = 2

			b �������� b.use_count() - 1 = 1 b��Դ���ͷ� , b.a1���ͷ�
			b.use_count() = 1 a.use_count() = 1
		*/
	}

	cout << "after AB }\n\n";

	{
		auto a{ make_shared<A>() };	/*=1 */
		auto b{ make_shared<B>() };	/*=1 */
		a->b2 = b;	/*=1*/
		a->Do();
		cout << "a->b1 = b b.use_count() = " << b.use_count() << '\n';
		b->a1 = a;	/*+1 =2 */
		cout << "b->a1 = a a.use_count() = " << a.use_count() << '\n';
	}

	(void)getchar();
	return 0;
}

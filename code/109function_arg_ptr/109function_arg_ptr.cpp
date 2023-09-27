#include <iostream>
#include <memory>

using namespace std;

void PtrFunction(const char* data,int size)
{
	cout << "sizeof(data) = " << sizeof(data) << '\n';
}

/*������������ ����ת����ָ��*/
void PtrFunction(const char data[])
{
	cout << "sizeof(data) = " << sizeof(data) << '\n';
}

/*���ݲ��� ��ȡ�����С*/
template<typename Ty,size_t SIZE>
void TestMen(Ty (&data)[SIZE])
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

int main(int argc, char* argv[])
{
	char data[]{"test mem ptr"};

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
	(void)getchar();
	return 0;
}

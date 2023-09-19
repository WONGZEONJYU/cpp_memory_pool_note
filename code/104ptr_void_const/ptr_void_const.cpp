#include <iostream>

using namespace std;

struct Frame{
    void* ctx;
};

static void _about_void_pointer()
{
    /*void ָ���ָ������ת��*/
    void* ptr1{ malloc(1024) };
    free(ptr1);

    int num{ 1 };
    void* ptr{ &num };
    int* ptr2{ static_cast<int*>(ptr) }; //void * 
    int* ptr3{ (int*)ptr };    /*C���,��cpp�²��Ƽ�ʹ��*/
    //static_cast ������һЩ��֤
    const int* cptr1{ new int[1024] };
    volatile int* vptr1{ new int[1024] };

    //int* ptr4 = static_cast<int*>(cptr1); /* static_cast�޷�ȥ�� ��const/volatile���Եı��� */
    int* ptr4{ (int*)(cptr1) };    /*C���,��cpp�²��Ƽ�ʹ��*/
    int* ptr6{ const_cast<int*>(cptr1) }; //ȥ��const
    int* ptr8{ const_cast<int*>(vptr1) }; /*ȥ��volatile*/

    unsigned char* ucptr{ new unsigned char[1024] };
    //int* ptr5 = static_cast<int*>(ucptr);
    auto ptr5{ (int*)ucptr }; /*C���,��cpp�²��Ƽ�ʹ��*/
    auto ptr7{ reinterpret_cast<int*>(ucptr) }; /*�滻ָ������*/

    delete[]ucptr;
    delete[]cptr1;
    delete[]vptr1;
    /*����ָ���������ת��,��Ӱ���ͷ�*/
}

static void _about_const_pointer()
{
    /*����ָ���ָ�볣��*/
    const int i1{ 100 };
    const int* pi1{ &i1 };/*ָ������ָ��*/
    // (*pi1)++; /*ָ���ֵ�����޸�*/
    int const* pi2{ &i1 }; /*ͬ��*/
    /*ָ�뱾���ǳ��� , ָ�����޸�*/

    int* const pi3{ new int };
    //pi3++;
    //pi3 = new int;
    *pi3 = 200;
    delete pi3;
    const int* const pi4{ &i1 };    /*ָ���ֵ�������޸�*/
/*
    pi4 = new int;
    *pi4 = 300;
*/
}


int main(int argc, char* argv[])
{
    //_about_void_pointer();
    _about_const_pointer();
	(void)getchar();
	return 0;
}

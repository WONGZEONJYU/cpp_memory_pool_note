#include <iostream>

using namespace std;

struct Frame{
    void* ctx;
};

static void _about_void_pointer()
{
    /*void 指针和指针类型转换*/
    void* ptr1{ malloc(1024) };
    free(ptr1);

    int num{ 1 };
    void* ptr{ &num };
    int* ptr2{ static_cast<int*>(ptr) }; //void * 
    int* ptr3{ (int*)ptr };    /*C风格,在cpp下不推荐使用*/
    //static_cast 增加了一些验证
    const int* cptr1{ new int[1024] };
    volatile int* vptr1{ new int[1024] };

    //int* ptr4 = static_cast<int*>(cptr1); /* static_cast无法去除 带const/volatile属性的变量 */
    int* ptr4{ (int*)(cptr1) };    /*C风格,在cpp下不推荐使用*/
    int* ptr6{ const_cast<int*>(cptr1) }; //去掉const
    int* ptr8{ const_cast<int*>(vptr1) }; /*去掉volatile*/

    unsigned char* ucptr{ new unsigned char[1024] };
    //int* ptr5 = static_cast<int*>(ucptr);
    auto ptr5{ (int*)ucptr }; /*C风格,在cpp下不推荐使用*/
    auto ptr7{ reinterpret_cast<int*>(ucptr) }; /*替换指针类型*/

    delete[]ucptr;
    delete[]cptr1;
    delete[]vptr1;
    /*无论指针类型如何转变,不影响释放*/
}

static void _about_const_pointer()
{
    /*常量指针和指针常量*/
    const int i1{ 100 };
    const int* pi1{ &i1 };/*指向常量的指针*/
    // (*pi1)++; /*指向的值不能修改*/
    int const* pi2{ &i1 }; /*同上*/
    /*指针本身是常量 , 指向不能修改*/

    int* const pi3{ new int };
    //pi3++;
    //pi3 = new int;
    *pi3 = 200;
    delete pi3;
    const int* const pi4{ &i1 };    /*指向和值都不能修改*/
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

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    cout << "101 pointer\n";
    /*p1存在栈中*/
    /*p1指向的空间在堆中*/
    int* p1 { new int };
    /* *间接符号,间接访问*/
    *p1 = 101;
    int i {10};
    cout << "i = " << i << '\n';
    int* p2 { &i };
    *p2 = 102;
    cout << "i = " << i << '\n';
    cout << "p1 = " << p1 << '\n';

    cout << "sizeof(p1) = " << sizeof(p1) << '\n';
    cout << "sizeof(*p1) = " << sizeof(*p1) << '\n';
    delete p1;

    cout << "after delete p1 = " << p1 << '\n';

    if (p1) {
        cout << "p1 not empty?\n";
    }
    p1 = nullptr; // nullptr c++11 NULL 0
    delete p1;
    if (!p1) {
        cout << "p1 is empty!\n";
    }
    //delete p1;

	_CRT_UNUSED(getchar());
	return 0;
}

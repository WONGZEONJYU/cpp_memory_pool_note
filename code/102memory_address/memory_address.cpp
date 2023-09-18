#include <iostream>

using namespace std;

int g1, g2{ 0 }, g3{ 1 },g4{ 2 }; 
static int sg1{ 3 };

int main(int argc, char* argv[])
{
    static int s1{ 5 };
    cout << "memory address! cppds.com" <<     
            "\ncode area main() = " << main << /* ´úÂëÇø .text */
            "\nglobal_Uninitialized &g1 = " << &g1 <<
            "\nglobal_initialized to 0 &g2 = " << &g2 << 
            "\nglobal_initialized to 1 &g3 = " << &g3 << 
            "\nglobal_initialized to 2 &g4 = " << &g4 << 
            "\nstatic global_initialized to 3 &sg1 = " << &sg1 << 
            "\nstatic local_initialized to 5 &s1 = " << &s1 << '\n';

    int* p1{ new int }, *p2{ new int };

    cout << "Heap space address p1 = " << p1 << 
            "\nHeap space address p2 = " << p2 << 
            "\nThe stack space address of the pointer variable &p1 = " << &p1 << 
            "\nThe stack space address of the pointer variable &p2 = " << &p2 << '\n';

    int i1{ 100 };
    int i2{ 101 };

    cout << "stack space address &i1 = " << &i1 << 
            "\nstack space address &i2 = " << &i2 << '\n';

    delete p1,delete p2;
    p1 = p2 = nullptr;
    (void)getchar();
	return 0;
}
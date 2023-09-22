#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	/*≥ı ºªØ*/

	shared_ptr<int> sp1(new int);
	shared_ptr<int[]> sp2(new int[1024]);
	*sp1 = 10;
	sp2[0] = 100;
	auto d1{ sp1.get() /*sp1.operator->()*/};


	(void)getchar();
	return 0;
}


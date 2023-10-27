#include <iostream>
#include "xcrypt.h"

using namespace std;

int main(int argc, char* argv[])
{
	XCrypt crypt;
	crypt.Init("12345678");

	char out[1024]{};

	auto en_size{ crypt.Encrypt("abcdefgh",24, out,true) };/*8的倍数*/
	cout << "en_size = " << en_size << "\nAfter encryption : " << 
			out << "\n";

	en_size = crypt.Encrypt("abcdefg", 9, out, true);/*非8的倍数*/
	cout << "en_size = " << en_size << "\nAfter encryption : " <<
		out << "\n";

	(void)getchar();
	return 0;
}


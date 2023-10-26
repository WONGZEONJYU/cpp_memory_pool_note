#include <iostream>
#include "xcrypt.h"

using namespace std;

int main(int argc, char* argv[])
{

	XCrypt crypt;
	crypt.Init("12345678");

	char out[1024]{};

	auto en_size{ crypt.Encrypt("abcdefg",7, out,true) };
	cout << "en_size = " << en_size << "\n";

	(void)getchar();
	return 0;
}


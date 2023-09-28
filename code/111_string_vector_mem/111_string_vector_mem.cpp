#include <iostream>
#include <vector>

using namespace std;

class XData
{
public:
	XData() { cout << __FUNCTION__ << '\n'; }
	~XData() { cout << __FUNCTION__ << '\n'; }
	
	XData(const XData& o) {
		index = o.index;
		cout << "Copy XData " << index << '\n';
	}

	XData& operator=(const XData& o) {

		if (this != &o){
			index = o.index;
			cout << "=XData " << index << '\n';
		}
		return *this;
	}

	int index{};
};

int main(int argc, char* argv[])
{
	(void)getchar();
	return 0;
}


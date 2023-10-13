#include <iostream>
#include <memory>
#include <xutility>

using namespace std;

class XData
{
public:

	XData() { cout << __FUNCTION__ << " " << index << "\n"; }

	XData(const XData& o) {
		index = o.index;
		cout << "copy " << __FUNCTION__ << " " << index << "\n";

	}

	XData& operator=(const XData& o) {

		if (this != &o) {
			index = o.index;
			cout << __FUNCTION__ << " " << index << "\n";
		}

		return *this;
	}

	~XData() { cout << __FUNCTION__ << " " << index << "\n"; }

	int index{};
};

int main(int argc,char* argv[])
{
	constexpr int size{ 3 };
	auto data{ static_cast<XData*>(malloc(size * sizeof(XData))) };

	for (size_t i {}; i < size; i++) {
		std::construct_at(&data[i]);
	}

    (void)getchar();
    return 0;
}


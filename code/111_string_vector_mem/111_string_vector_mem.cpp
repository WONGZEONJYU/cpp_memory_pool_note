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

vector<XData> TestVec(vector<XData>& data)
{
	cout << "TestVec data :" << data.data() << '\n';
	vector<XData> re;
	re.resize(3);
	cout << "re data : " << re.data() << '\n';
	return re;
}

int main(int argc, char* argv[])
{
	{
		vector<XData> vd;
#if 1
		XData d;
		d.index = 1;
		vd.push_back(d);
		d.index = 2;
		vd.push_back(d);
		d.index = 3;
		vd.push_back(d);
		cout << "vd.data : " << vd.data() << '\n';
		auto rd{ TestVec(vd) };
		cout << "rd.data : " << rd.data() << '\n';
		cout << "re Byte = " << rd.size() * sizeof(XData) << '\n';
		cout << "re cap = " << rd.capacity() << '\n';
#endif
	}

	(void)getchar();
	return 0;
}


#include <iostream>

using namespace std;

class Data
{
public:
	static int count;
	int index{};
	Data() {
		index = ++count;
		cout << index << ' ' << __FUNCTION__ << '\n';
	}
	~Data() {
		cout << index << ' ' << __FUNCTION__ << '\n';
	}
};

int Data::count{};

static void _unique_ptr_()
{
	/*RAII ��Դ��ȡ����ʼ�� (Resource Acquisition Is Initialization)*/
	{
		cout << "begin ============unique_ptr init============ begin\n";
		unique_ptr<int> p1(new int);
		unique_ptr<Data> p2(new Data);
		cout << "========1=========\n";
		auto p3{ make_unique<Data>() };

		/*������ָ��*/
		unique_ptr<Data> p4;
		unique_ptr<int[]> pa1{ make_unique<int[]>(1024) };
		unique_ptr<int[]> pa2(new int[1024]);
		unique_ptr<Data[]> pa3(new Data[3]);
		cout << "end ============unique_ptr init============ end\n\n";

		/*unique_ptr����ָ����ʺ��ƶ����츳ֵ*/
		cout << "begin ====================unique_ptr access==================== begin\n";
		*p1 = 10;
		cout << "p1 value = " << *p1 << '\n';
		cout << "(*p2).index = " << (*p2).index << '\n';
		cout << "p2->index = " << p2->index << '\n';
		auto d1{ new Data()};
		unique_ptr<Data> p5(d1);
		cout << "p5 address : " << p5 << '\n';
		cout << "d1 address : " << d1 << '\n';
		cout << "p5.get() : " << p5.get() << '\n';
		pa2[0] = 1;
		pa2[1] = 2;
		cout << "pa3[0].index = " << pa3[1].index << '\n';
		cout << "pa3.get()[1].index = " << pa3.get()[2].index << '\n';
		cout << "end ====================unique_ptr access==================== end\n\n";

		/*���ú��ƶ��ڴ���Դ*/
		cout << "begin ======================unique_ptr reset and move====================== begin\n";

		unique_ptr<Data> p6(new Data());
		/*
			���ɿ�������͸�ֵ

			unique_ptr(const unique_ptr&)            = delete;
			unique_ptr& operator=(const unique_ptr&) = delete;

			unique_ptr<Data> p7(p6);
			p7 = p6;
		*/
		/*֧���ƶ��������ƶ���ֵ p6�ͷ�����Ȩ,ת�Ƶ�p7*/
		unique_ptr<Data> p7(std::move(p6));
		unique_ptr<Data> p8(new Data());
		p7 = std::move(p8);

		/*���ÿռ�,ԭ�ռ�����*/
		p7.reset(new Data());
		cout << "end ======================unique_ptr reset and move====================== end\n\n";

		/*�ͷ�����Ȩ���Զ���ռ�ɾ������*/
		cout << "begin ======================Release ownership ====================== begin\n";
		
		cout << "begin p7 = nullptr\n";
		p7 = nullptr;/*�����ͷ�*/
		cout << "end p7 = nullptr\n";

		/*�ͷ�����Ȩ,��������ָ�����ָ�뷵��,���ֶ��ͷ�,��������*/

		cout << "begin p9 \n";
		unique_ptr<Data> p9(new Data());
		auto ptr9{ p9.release() };
		delete ptr9;
		cout << "end p9 \n";
		
		cout << "end ======================Release ownership ====================== end\n\n";

		/*�Զ���ɾ������*/
		cout << "begin ========================customize deleter========================\n";

		struct XPacket {	/*ģ�Ͳ�ռ���ڴ�*/
			unsigned char* data{};
			int size{};
		};

		class PacketDelete { /*ģ�Ͳ�ռ���ڴ�*/
		public:
			void Close() {
				cout << "Call PacketDelete Close!\n";
			}
			/*�˴�����str����ʵ������,û���κ�����*/
			void operator()(XPacket* p,const char* str = "default") const {
				cout << str << " call PacketDelete()\n";
				delete p->data;
				delete p;
			}
		};

		unique_ptr<XPacket, PacketDelete> pd1(new XPacket);
		unique_ptr<XPacket, PacketDelete> pd2(new XPacket);
		pd2.get_deleter().Close();/*���ֿ�����ĳЩ������Ҫ,���ͷ�ǰ��ЩԤ����*/
		pd2.get_deleter()(pd2.get() /*pd2.operator->()*/ , "pd2"); /* operator->() == get() */
		pd2.release();
		//pd2.get_deleter()(pd2.release(),"pd2");	/*���ַ�������,ͬ��*/

		/*lambda ��Ϊɾ����*/
		auto f { [](XPacket* p) {cout << "pd3 lambda\n"; delete p; } };
		unique_ptr< XPacket, decltype(f) > pd3 (new XPacket,f); 

		cout << "end ========================customize deleter========================\n\n";
	}
	
	cout << "\n========2=========\n";
}

int main(int argc, char** argv[])
{
	_unique_ptr_();
	(void)getchar();
	return 0;
}

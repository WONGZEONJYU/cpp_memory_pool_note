#include <iostream>

using namespace std;
/*重载全局的new和delete*/

void* operator new(size_t size)
{
	cout << __FUNCTION__ << " " << size << '\n';
	auto mem{ malloc(size) };
	if (!mem) {
		throw std::bad_alloc();
	}
	return mem;
}

void* operator new[](size_t size)
{
	cout << __FUNCTION__ << " " << size << '\n';
	auto mem{ malloc(size) };
	if (!mem) {
		throw std::bad_alloc();
	}
	return mem;
}

void operator delete(void* p)
{
	cout << __FUNCTION__ << '\n';
	std::free(p);
}

void operator delete[](void* p)
{
	cout << __FUNCTION__ << '\n';
	std::free(p);
}

namespace global_new_delete
{
	class TestMem
	{
	public:
		int index{};
		TestMem() { cout << __FUNCTION__ << '\n'; }
		~TestMem() { cout << __FUNCTION__ << '\n'; }
	};

	void test()
	{
		int* i1{ new int };
		delete i1;

		auto mem1{ new TestMem() };
		delete mem1;

		mem1 = nullptr;
		i1 = nullptr;

		int* arr1{ new int[1024] };
		delete[] arr1;

		TestMem* memarr1{ new TestMem[2] };
		delete[] memarr1;
	}
}

namespace class_new_delete
{
	class TestMem
	{
	public:
		int index{};
		TestMem() { cout << __FUNCTION__ << '\n'; }
		~TestMem() { cout << __FUNCTION__ << '\n'; }
		void* operator new(size_t size) {
			cout << __FUNCTION__ << " " << size << '\n';
			auto mem{ malloc(size) };
			if (!mem) {
				throw std::bad_alloc();
			}
			return mem;
		}
		void* operator new[](size_t size)
		{
				cout << __FUNCTION__ << " " << size << '\n';
				auto mem{ malloc(size) };
				if (!mem) {
					throw std::bad_alloc();
				}
				return mem;
		}

		void operator delete(void* p)
		{
			cout << __FUNCTION__ << '\n';
			std::free(p);
		}

		void operator delete[](void* p)
		{
			cout << __FUNCTION__ << '\n';
			std::free(p);
		}
	};

	void test()
	{
		auto mem1{ new TestMem() };
		delete mem1;
		mem1 = nullptr;

		TestMem* memarr1{ new TestMem[2] };
		delete[] memarr1; 
		memarr1 = nullptr;
	}
}

namespace placement_new_test
{
	class TestMem
	{
	public:
		int index{};
		TestMem() { cout << __FUNCTION__ << '\n'; }
		~TestMem() { cout << __FUNCTION__ << '\n'; }

		void* operator new(size_t size) {
			cout << __FUNCTION__ << " " << size << '\n';
			auto mem{ malloc(size) };
			if (!mem) {
				throw std::bad_alloc();
			}
			return mem;
		}

		void* operator new[](size_t size)
		{
				cout << __FUNCTION__ << " " << size << '\n';
				auto mem{ malloc(size) };
				if (!mem) {
					throw std::bad_alloc();
				}
				return mem;
		}

		void* operator new(size_t size, void* ptr) noexcept
		{
			cout << __FUNCTION__ << '\n';
			return ptr;
		}

		void operator delete(void* p)
		{
			cout << __FUNCTION__ << '\n';
			std::free(p);
		}

		void operator delete[](void* p)
		{
			cout << __FUNCTION__ << '\n';
			std::free(p);
		}
	};

	void test()
	{
		int buf1[1024]{};
		TestMem* mem1{ ::new(buf1) TestMem() };
		cout << "buf1 addr : " << buf1 << '\n'
			<< "buf1 addr : " << mem1 << "\n";
		mem1->~TestMem();

		int* buf2{ new int[1024] {} };
		auto mem2{ ::new(buf2) TestMem() };
		mem2->~TestMem();
		::delete[] buf2;
		buf2 = nullptr;

		int* buf3{ new int[1024] {} };
		auto mem3{ new(buf3) TestMem };
		cout << "buf3 addr : " << buf3 << '\n'
		 << "mem3 addr : " << mem3 << "\n";
		mem3->~TestMem();
		::delete[] buf3;
		buf3 = nullptr;
	}
}

int main(int argc, char* argv[])
{
	//global_new_delete::test();
	//class_new_delete::test();
	placement_new_test::test();
	(void)getchar();

	return 0;
}


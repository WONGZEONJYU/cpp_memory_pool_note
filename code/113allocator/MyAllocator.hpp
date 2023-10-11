#ifndef MYALLOCATOR
#define MYALLOCATOR

template<typename Ty>
class MyAllocator
{
public:
	using value_type = Ty;

	MyAllocator() {}

	template<typename Other>
	MyAllocator(const MyAllocator<Other>&) {}

	void deallocate(Ty* const ptr,const size_t count)
	{
		std::cout << __FUNCTION__ << " " << count << "\n";
		free(ptr);
	}

	Ty* allocate(const size_t count) {
		std::cout << __FUNCTION__ << " " << count << "\n";
		std::cout << "typeid(Ty).name() = " << typeid(Ty).name() << "\n";
		return static_cast<Ty*>(malloc(count * sizeof(Ty)));
	}
};

#endif

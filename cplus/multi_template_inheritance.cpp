#include<iostream>
#include<thread>

template<typename a, typename b>
class c1
{
 public:
	void print0(void)
	{
		std::wcout << sizeof(a) << ' ' << sizeof(b) << '\n';
	}
};

template<typename c>
class c2
{
   public:
	void print1(void)
	{
		std::wcout << sizeof(c) << '\n';
	}
};


template<typename A, typename B, typename C>
class multi : public c1<A, B>, public c2<C>
{
    public:
	void print2(void)
	{
		this->print0();
		this->print1();  //or
		c1<A, B>::print0();
		c2<C>::print1();
	}
};

int main()
{
	multi<short,long, double> obj;
	obj.print2();

	std::this_thread::sleep_for(std::chrono::seconds(1));
	return EXIT_SUCCESS;
}

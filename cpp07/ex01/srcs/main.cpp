#include "iter.hpp"

void	increment(int &a)
{
	a += 1;
}

void	print(int const &a)
{
	std::cout << "value: " << a << "; ";
}

void	to_upper(char &a)
{
	a = toupper(a);
}

void	print_char(char const &a)
{
	std::cout << "char : " << a << "; ";
}

int main( void )
{
	{
		int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		::iter(a, 10, print);
		std::cout << std::endl;
		::iter(a, 10, increment);
		::iter(a, 10, print);
		std::cout << std::endl;
	}
	{
		char b[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
		::iter(b, 10, print_char);
		::iter(b, 10, to_upper);
		std::cout << std::endl;
		::iter(b, 10, print_char);
		std::cout << std::endl;
	}
	return 0;
}
#include "Array.hpp"

int main( void )
{
	Array<int> a(7);
	Array<char>	b;

	std::cout << a.size() << std::endl;
	std::cout << b.size() << std::endl;

	try
	{
		a[8];
	}
	catch(const char* e)
	{
		std::cerr << "Error: " << e << std::endl;
	}
	
	return 0;
}
#include "easyfind.hpp"
#include <vector>
#include <list>

int main( void )
{
	{
		std::cout << "------------------Vector test------------------" << std::endl;
		std::vector<int> a;
		a.push_back(2);
		a.push_back(0);
		a.push_back(-15);
		a.push_back(5);
		a.push_back(15);
		a.push_back(30);
		try
		{
			std::cout << *::easyfind(a, 15) << std::endl;
		}
		catch(const char *e)
		{
			std::cerr << e << std::endl;
		}
		try
		{
			std::cout << *::easyfind(a, 42) << std::endl;
		}
		catch(const char *e)
		{
			std::cerr << e << std::endl;
		}
	}
	{
		std::cout << "------------------List test------------------" << std::endl;
		std::list<int> b;
		b.push_back(2);
		b.push_back(0);
		b.push_back(-15);
		b.push_back(5);
		b.push_back(15);
		b.push_back(30);
		try
		{
			std::cout << *::easyfind(b, 15) << std::endl;
		}
		catch(const char *e)
		{
			std::cerr << e << std::endl;
		}
		try
		{
			std::cout << *::easyfind(b, 42) << std::endl;
		}
		catch(const char *e)
		{
			std::cerr << e << std::endl;
		}
	}
	return 0;
}
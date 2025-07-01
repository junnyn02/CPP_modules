#include "Array.hpp"

int main( void )
{
	Array<int> a(7);
	Array<char>	b;

	std::cout << "int(a) created with n size. size is: " << a.size() << std::endl;
	std::cout << "char(b) created with no parameters. size is: " << b.size() << std::endl;

	try
	{
		std::cout << "try access int(a)[7] : ";
		std::cout << a[7] << std::endl;
	}
	catch(const char* e)
	{
		std::cerr << "Error: " << e << std::endl;
	}
	std::cout << "fill int(a) array : ";
	for (int i = 0; i < 7; i++)
	{
		a[i] = i;
	}
	for (int i = 0; i < 7; i++)
	{
		try
		{
			std::cout << a[i] << " ";
		}
		catch(const char* e)
		{
			std::cerr << "Error: " << e << std::endl;
		}
	}
	std::cout << std::endl << "-----------------------CPY TEST-----------------------" << std::endl;
	Array<int> cpy(a);
	std::cout << "int(cpy) created by copy of int(a). size is: " << cpy.size() << std::endl;
	std::cout << "int(cpy) : ";
	for (int i = 0; i < 7; i++)
	{
		try
		{
			std::cout << cpy[i] << " ";
		}
		catch(const char* e)
		{
			std::cerr << "Error: " << e << std::endl;
		}
	}
	std::cout << std::endl << "Modify int(a): ";
	for (int i = 0; i < 7; i++)
	{
		a[i] = i + 1;
	}
	for (int i = 0; i < 7; i++)
	{
		try
		{
			std::cout << a[i] << " ";
		}
		catch(const char* e)
		{
			std::cerr << "Error: " << e << std::endl;
		}
	}
	std::cout << std::endl << "what's inside int(cpy) mustn't change: ";
	for (int i = 0; i < 7; i++)
	{
		try
		{
			std::cout << cpy[i] << " ";
		}
		catch(const char* e)
		{
			std::cerr << "Error: " << e << std::endl;
		}
	}
	std::cout << std::endl;
	return 0;
}
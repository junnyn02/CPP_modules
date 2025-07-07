#include "Array.hpp"
#include <stdlib.h>

#define MAX_VAL 750

int main( void )
{
	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;//
	}
	std::cout << "------------------------My TEST-----------------------" << std::endl;
	Array<int> a(7);
	Array<char>	b;

	std::cout << "int(a) created with n size. size is: " << a.size() << std::endl;
	std::cout << "char(b) created with no parameters. size is: " << b.size() << std::endl;
	try
	{
		std::cout << "try access char(b)[0] : ";
		std::cout << b[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "try access int(a)[7] : ";
		std::cout << a[7] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
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
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
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
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
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
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "what's inside int(cpy) mustn't change: ";
	for (int i = 0; i < 7; i++)
	{
		try
		{
			std::cout << cpy[i] << " ";
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	return 0;
}
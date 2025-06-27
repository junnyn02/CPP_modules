#include "Base.hpp"
#include <cstdlib>
#include <ctime>

Base	*generate(void)
{
	srand(time(0));
    
    int random = rand() % 3;
    Base	*ptr = NULL;
    switch(random)
	{
        case 0:
			// std::cout << "A" << std::endl;
			ptr = new A();
			break;
        case 1:
			// std::cout << "B" << std::endl;
			ptr = new B();
			break;
        case 2:
			// std::cout << "C" << std::endl;
			ptr = new C();
			break;
    }
	return (ptr);
}

void	identify(Base *p)
{
	std::cout << "The object pointed to by p is ";
	A* a = dynamic_cast<A*>(p);
	if (a)
		std::cout << "A" << std::endl;
	B* b = dynamic_cast<B*>(p);
	if (b)
		std::cout << "B" << std::endl;
	C* c = dynamic_cast<C*>(p);
	if (c)
		std::cout << "C" << std::endl;
}

void	identify(Base &p)
{
	std::cout << "The object referenced to by p is ";
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				C &c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch(const std::exception& e)
			{
			}
		}
	}
}

int	main()
{
	Base *ptr = NULL;
	ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;
	return (0);
}
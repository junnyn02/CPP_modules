#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: Need one (and only one) argument" << std::endl;
		return (0);
	}
	try
	{
		RPN rpn(av[1]);
		rpn.parser();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
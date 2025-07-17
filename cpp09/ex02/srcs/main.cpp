#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: Need at least 1 argument" << std::endl;
		return (0);
	}
	try
	{
		PmergeMe pm(av, ac);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}

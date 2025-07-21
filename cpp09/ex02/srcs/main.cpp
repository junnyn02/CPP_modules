#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	// std::vector<int> jacobsthal;
    // jacobsthal.push_back(0);
    // jacobsthal.push_back(1);
    // while (jacobsthal.back() < 25 + 1)
    // {
    //     int size = jacobsthal.size();
    //     int next = (size == 1) ? 1 : jacobsthal[size - 1] + 2 * jacobsthal[size - 2];
    //     std::cout << jacobsthal[size-1] << " " << jacobsthal[size-2] << "; next =" << next << std::endl;
	// 	jacobsthal.push_back(next);
    // }
    // for (size_t i = 0; i < jacobsthal.size(); ++i)
	// {
	// 	std::cout << std::endl << jacobsthal[i] <<" ";
	// }
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

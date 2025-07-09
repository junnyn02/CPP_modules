#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: Need one (and only one) argument" << std::endl;
		return (0);
	}
	try
	{
		BitcoinExchange btc(av[1], "data.csv");
		btc.fillDB();
		btc.checkInput();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
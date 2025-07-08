#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <algorithm>
# include <map>
# include <stdexcept>
# include <fstream>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_data;
		std::ifstream					_input;
		std::ifstream					_csv;
		BitcoinExchange(void);

	public:
		BitcoinExchange(char const *, char const *);
		~BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &cpy);
		BitcoinExchange	&operator=(BitcoinExchange const &assign);

		bool	checkFormat(std::string const &, std::string const &);
		void	fillDB(void);
		bool	checkInput(void);
};

# endif
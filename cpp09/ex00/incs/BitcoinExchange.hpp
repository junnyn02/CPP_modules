#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <algorithm>
# include <map>
# include <stdexcept>
# include <fstream>
# include <limits>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_data;
		// std::map<std::string, float>	_check;

		std::ifstream					_input;
		std::ifstream					_csv;

		bool							_leap_y;
		int								_year;
		int								_month;
		int								_day;
		BitcoinExchange(void);

	public:
		BitcoinExchange(char const *, char const *);
		~BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &cpy);
		BitcoinExchange	&operator=(BitcoinExchange const &assign);

		bool	checkFormat(std::string const &, std::string const &);
		void	fillDB(void);
		void	checkInput(void);

		void	checkDate(std::string const &);
		bool	validYear(std::string const &);
		bool	validMonth(std::string const &);
		bool	validDay(std::string const &);

		void	checkValue(std::string const &);
		void	convertValue(std::string const &);

		std::map<std::string, float>::iterator	findYear(void);
		std::map<std::string, float>::iterator	findMonth(std::map<std::string, float>::iterator &);
		std::map<std::string, float>::iterator	findDay(std::map<std::string, float>::iterator);

		int	diff(std::string const &, const int &) const;
};

# endif
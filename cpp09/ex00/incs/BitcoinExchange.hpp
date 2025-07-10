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

		std::ifstream					_input;
		std::ifstream					_csv;

		bool							_leap_y;
		int								_year;
		int								_month;
		int								_day;

		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &cpy);
		BitcoinExchange	&operator=(BitcoinExchange const &assign);

	public:
		BitcoinExchange(char const *, char const *);
		~BitcoinExchange(void);

		void	fillDB(void);
		void	checkInput(void);
		void	checkDate(std::string const &);
		void	checkValue(std::string const &) const;
		void	convertValue(std::string const &);
		
		bool	checkFormat(std::string const &, std::string const &);
		bool	validYear(std::string const &);
		bool	validMonth(std::string const &);
		bool	validDay(std::string const &);

		std::map<std::string, float>::iterator	findYear(void);
		std::map<std::string, float>::iterator	findMonth(std::map<std::string, float>::iterator &);
		std::map<std::string, float>::iterator	findDay(std::map<std::string, float>::iterator);

		int	diff(std::string const &, const int &) const;
};

# endif
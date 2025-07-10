#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <algorithm>
# include <stack>
# include <stdexcept>
# include <limits>
# include <cerrno>

class RPN
{
	private:
		std::stack<int>	_stack;
		std::string 	_input;
		int				_result;

		RPN(void);
		RPN(RPN const &cpy);
		RPN	&operator=(RPN const &assign);

	public:
		RPN(std::string const &);
		~RPN(void);
		void	parser(void);
		void	calcul(char const &);
		void	pushNumber(std::string::iterator &);

		bool	isop(std::string::iterator &) const;
		bool	isnumber(std::string::iterator &) const;
		bool		add(int const &, int const &);
		bool		substract(int const &, int const &);
		bool		multiply(int const &, int const &);
};

# endif
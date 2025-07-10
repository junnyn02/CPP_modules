#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <algorithm>
# include <stack>
# include <stdexcept>
# include <limits>

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
		bool	isop(char const &) const;

};

# endif
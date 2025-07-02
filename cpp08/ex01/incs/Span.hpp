#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <stdexcept>

class Span
{
	private:
		unsigned int		_size;
		std::vector<int>	_tab;
		Span(void);
	
	public:
		Span(unsigned int N);
		~Span(void);
		Span(Span const &cpy);
		Span	&operator=(Span const &assign);

		void	addNumber(int const &x);
		void	addNumber(std::vector<int>::iterator it, std::vector<int>::iterator ite);
		int 	shortestSpan(void) const;
		int 	longestSpan(void) const;

		class NoSpaceLeft : public std::exception
		{
			public:
				virtual const char* what() const throw(); 
		};

		class NotEnoughNumber : public std::exception
		{
			public:
				virtual const char* what() const throw(); 
		};
};

# endif
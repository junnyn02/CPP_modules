#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <stack>
# include <deque>
# include <stdexcept>

# define COLOR_RESET   "\033[0m"
# define COLOR_GREEN   "\033[1;32m"
# define COLOR_YELLOW  "\033[1;33m"
# define COLOR_CYAN    "\033[1;36m"

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void);
		~MutantStack(void);
		MutantStack(MutantStack const &cpy);
		MutantStack	&operator=(MutantStack const &assign);
		
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin(void);
		iterator end(void);
		const_iterator cbegin(void);
		const_iterator cend(void);
		reverse_iterator rbegin(void);
		reverse_iterator rend(void);
		const_reverse_iterator crbegin(void);
		const_reverse_iterator crend(void);
};

# include "MutantStack.tpp"

# endif
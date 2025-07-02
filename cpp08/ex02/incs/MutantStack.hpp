#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <stack>
# include <stdexcept>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void);
		~MutantStack(void);
		MutantStack(MutantStack const &cpy);
		MutantStack	&operator=(MutantStack const &assign);

		typedef typename std::stack<T>::iterator ;

};

# include "MutantStack.tpp"

# endif
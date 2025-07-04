#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <stack>
# include <deque>
# include <stdexcept>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void);
		~MutantStack(void);
		MutantStack(MutantStack const &cpy);
		MutantStack	&operator=(MutantStack const &assign);

		// typedef creates an alias for the existent type
		// and typename tells the compiler that std::vector<T>::size_type
		// is a type and not a member.
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		iterator begin(void);
		iterator end(void);
		const_iterator cbegin(void);
		const_iterator cend(void);
};

# include "MutantStack.tpp"

# endif
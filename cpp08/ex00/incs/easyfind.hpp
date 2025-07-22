#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

# define COLOR_RESET   "\033[0m"
# define COLOR_GREEN   "\033[1;32m"
# define COLOR_YELLOW  "\033[1;33m"
# define COLOR_CYAN    "\033[1;36m"

template< typename T >
typename T::const_iterator easyfind( T const &a, int const &x)
{
	typename T::const_iterator it = a.begin();	
	typename T::const_iterator ite = a.end();
	typename T::const_iterator val = std::find(it, ite, x);
	if (val == ite)
		throw ("No match found");
	return val;
}

# endif
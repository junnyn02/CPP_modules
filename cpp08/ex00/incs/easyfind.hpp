#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

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
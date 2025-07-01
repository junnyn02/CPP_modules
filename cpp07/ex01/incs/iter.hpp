#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template< typename T, typename F >
void iter( T *a, size_t length, F f)
{
	if (!a)
		return ;
	for (size_t i = 0; i < length; i++)
		f(a[i]);
}

#endif
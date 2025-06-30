#ifndef	ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>

template< typename T >
class Array
{
	private:
		T *_array;
		unsigned int _size;
	
	public:
		Array(void);
		Array(unsigned int const &n);
		~Array(void);
		Array(Array const &cpy);
		
		Array	&operator=(Array const &assign);
		T	&operator[](unsigned int const &index);
		
		unsigned int const	&size(void) const;
};

# include "Array.tpp"

#endif
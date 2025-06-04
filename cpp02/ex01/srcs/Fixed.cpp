/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/05/20 11:16:08 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	_fixedPoint = 0;
}

Fixed::Fixed( const int nb )
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPoint = nb << _fractBits;
}

Fixed::Fixed( const float nb )
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPoint = roundf(nb * (1 << _fractBits));
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( Fixed const & cpy )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Fixed & Fixed::operator=( Fixed const & assign )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &assign)
		this->_fixedPoint = assign.getRawBits();
	return *this;
}

int	Fixed::getRawBits( void ) const
{
	return(this->_fixedPoint);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPoint = raw;
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->_fixedPoint / (float)(1 << _fractBits));
}

int	Fixed::toInt( void ) const
{
	return (this->_fixedPoint >> _fractBits);
}

std::ostream &	operator<<( std::ostream & o, Fixed const &i )
{
	o << i.toFloat();
	return (o);
}
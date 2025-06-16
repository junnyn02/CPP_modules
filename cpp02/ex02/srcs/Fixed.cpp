/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/16 11:28:06 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void )
{
	if (MSG)
		std::cout << "Default constructor called" << std::endl;
	_fixedPoint = 0;
}

Fixed::Fixed( const int nb )
{
	if (MSG)
		std::cout << "Int constructor called" << std::endl;
	this->_fixedPoint = nb << _fractBits;
}

Fixed::Fixed( const float nb )
{
	if (MSG)
		std::cout << "Float constructor called" << std::endl;
	this->_fixedPoint = roundf(nb * (1 << _fractBits));
}

Fixed::~Fixed( void )
{
	if (MSG)
		std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( Fixed const & cpy )
{
	if (MSG)
		std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Fixed & Fixed::operator=( Fixed const & assign )
{
	if (MSG)
		std::cout << "Copy assignment operator called" << std::endl;
	if (this != &assign)
		this->_fixedPoint = assign.getRawBits();
	return *this;
}

int	Fixed::getRawBits( void ) const
{
	if (MSG)
		std::cout << "getRawBits member function called" << std::endl;
	return(this->_fixedPoint);
}

void	Fixed::setRawBits( int const raw )
{
	if (MSG)
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

bool	Fixed::operator>(Fixed comp) const
{
	return (this->toFloat() > comp.toFloat());
}

bool	Fixed::operator>=(Fixed comp) const
{
	return (this->toFloat() >= comp.toFloat());
}

bool	Fixed::operator<(Fixed comp) const
{
	return (this->toFloat() < comp.toFloat());
}

bool	Fixed::operator<=(Fixed comp) const
{
	return (this->toFloat() <= comp.toFloat());
}

bool	Fixed::operator==(Fixed comp) const
{
	return (this->toFloat() == comp.toFloat());
}

bool	Fixed::operator!=(Fixed comp) const
{
	return (this->toFloat() != comp.toFloat());
}

float	Fixed::operator+( Fixed nb ) const
{
	return (this->toFloat() + nb.toFloat());
}

float	Fixed::operator-( Fixed nb ) const
{
	return (this->toFloat() - nb.toFloat());
}

float	Fixed::operator*( Fixed nb ) const
{
	return (this->toFloat() * nb.toFloat());
}

float	Fixed::operator/( Fixed nb ) const
{
	return (this->toFloat() / nb.toFloat());
}

Fixed&	Fixed::operator++()
{
	++this->_fixedPoint;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	++this->_fixedPoint;
	return (tmp);
}

Fixed	Fixed::operator--()
{
	return (this->_fixedPoint--);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	--this->_fixedPoint;
	return (tmp);
}

Fixed & Fixed::min(Fixed &a, Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	else
		return (b);
}

const Fixed & Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	else
		return (b);
}

Fixed & Fixed::max(Fixed &a, Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	else
		return (b);
}

const Fixed & Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	else
		return (b);
}
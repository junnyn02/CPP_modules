/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:28:28 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/16 11:54:18 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0)
{
	if (MSG)
		std::cout << "Default no parameters constructor called" << std::endl;
}

Point::Point( const float x, const float y) : _x(x), _y(y)
{
	if (MSG)
		std::cout << "Default constructor called" << std::endl;
}

Point::~Point( void )
{
	if (MSG)
		std::cout << "Destructor called" << std::endl;
}


Point::Point( Point const & cpy ) : _x(cpy.getX()), _y(cpy.getY())
{
	if (MSG)
		std::cout << "Copy constructor called" << std::endl;
}

Point & Point::operator=( Point const & assign )
{
	if (MSG)
		std::cout << "Copy assignment operator called" << std::endl;
	if (this != &assign)
		return (*this);
	return (*this);
}

Fixed Point::getX( void ) const
{
	return (this->_x);
}

Fixed const	Point::getY( void ) const
{
	return (this->_y);
}

std::ostream &	operator<<( std::ostream & o, Point const &i )
{
	o << "x = " << i.getX() << "; y = " << i.getY();
	return (o);
}
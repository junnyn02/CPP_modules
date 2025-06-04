/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:28:28 by junguyen          #+#    #+#             */
/*   Updated: 2025/05/21 17:30:47 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0)
{
}

Point::Point( const float x, const float y) : _x(x), _y(y)
{
}

Point::~Point( void )
{
}


Point::Point( Point const & cpy ) : _x(cpy.getX()), _y(cpy.getY())
{
}

Point & Point::operator=( Point const & assign )
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &assign){
		((Fixed &)this->_x) = assign._x; //ca marche mais a ne pas faire
		((Fixed &)this->_y) = assign._y; //ca marche mais a ne pas faire
		// return (cpy); //do smth
	}
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
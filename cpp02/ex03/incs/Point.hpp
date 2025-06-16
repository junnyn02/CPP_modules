/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:25:54 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/16 11:53:50 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point
{
private:
	Fixed const _x;
	Fixed const	_y;
	
public:
	Point( void );
	Point( const float x, const float y);
	Point( Point const &cpy );
	~Point( void );

	Point &operator=( Point const &assign );
	Fixed	getX( void )const;
	Fixed const	getY( void )const;
};

std::ostream &	operator<<( std::ostream & o, Point const &i );

bool bsp( Point const a, Point const b, Point const c, Point const point);
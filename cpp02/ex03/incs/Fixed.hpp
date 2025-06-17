/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:16 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/17 11:28:49 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

# ifndef MSG
#	define MSG 1
# endif

class	Fixed{
	
	private:
		int					_fixedPoint;
		static const int	_fractBits = 8;

	public:
		Fixed( void );
		Fixed( const int nb );
		Fixed( const float nb );
		Fixed( Fixed const & cpy );
		~Fixed( void );

		Fixed &	operator=( Fixed const & assign );
		
		bool	operator>( Fixed comp ) const;
		bool	operator>=( Fixed comp ) const;
		bool	operator<( Fixed const comp ) const;
		bool	operator<=( Fixed const comp ) const;
		bool	operator==( Fixed const comp ) const;
		bool	operator!=( Fixed const comp ) const;

		float	operator+( Fixed nb ) const;
		float	operator-( Fixed nb ) const;
		float	operator*( Fixed nb ) const;
		float	operator/( Fixed nb ) const;

		Fixed &	operator++();
		Fixed	operator++(int);

		Fixed &	operator--();
		Fixed	operator--(int);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		float	toFloat( void ) const;
		int		toInt( void ) const;

		static	Fixed & min( Fixed &a, Fixed  &b);
		static	const Fixed & min( Fixed const &a, Fixed  const &b);

		static	Fixed & max( Fixed &a, Fixed  &b);
		static	const Fixed & max( Fixed const &a, Fixed  const &b);
};

std::ostream &	operator<<( std::ostream & o, Fixed const &i );

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:16 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/13 11:28:02 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	private:
		int					_fixedPoint;
		static const int	_fractBits = 8;

	public:
		Fixed(void);
		Fixed(Fixed const & cpy);
		~Fixed(void);

		Fixed &	operator=(Fixed const & assign);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
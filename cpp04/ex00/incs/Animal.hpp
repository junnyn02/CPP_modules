/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:16 by junguyen          #+#    #+#             */
/*   Updated: 2025/05/22 16:27:08 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class	Animal{
	
	protected:
		std::string	_type;

	public:
		Animal( void );
		Animal( std::string type );
		Animal( Animal const & cpy );
		virtual ~Animal( void );

		Animal &	operator=( Animal const & assign );

		std::string		getType( void ) const;
		virtual void	makeSound( void ) const;
};

#endif
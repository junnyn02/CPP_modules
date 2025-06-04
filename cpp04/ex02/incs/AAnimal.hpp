/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:16 by junguyen          #+#    #+#             */
/*   Updated: 2025/05/27 15:15:34 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class	AAnimal{
	
	protected:
		std::string	_type;

	public:
		AAnimal( void );
		AAnimal( std::string type );
		AAnimal( AAnimal const & cpy );
		virtual ~AAnimal( void );

		AAnimal &	operator=( AAnimal const & assign );

		std::string		getType( void ) const;
		virtual void	makeSound( void ) const = 0;
};

#endif
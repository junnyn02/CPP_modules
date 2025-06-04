/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:16 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/04 14:27:49 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class	Ice : public AMateria
{
	
	public:
		Ice( void );
		Ice( Ice const & cpy );
		virtual ~Ice( void );

		Ice &	operator=( Ice const & assign );

		std::string const		&getType( void ) const;

		virtual AMateria*	clone(void) const;
		virtual void	use( ICharacter &target );
};

#endif
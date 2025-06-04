/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:16 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/04 14:31:11 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class	Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_inventory[4];

		public:
		Character( void );
		Character( std::string const & name );
		Character( Character const & cpy );
		virtual ~Character( void );

		Character &	operator=( Character const & assign );

		virtual std::string const	&getName( void ) const;
		virtual void	equip( AMateria *m );
		virtual void	unequip( int idx );
		virtual void	use( int idx, ICharacter &target );
};

#endif
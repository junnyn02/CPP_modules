/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:19:39 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/10 14:39:41 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		std::string _name;
		Weapon	*_weapon;

	public:
		HumanB( std::string name);
		~HumanB( void );
		void	attack( void ) const;
		void	setWeapon( Weapon &new_weapon );
};

#endif
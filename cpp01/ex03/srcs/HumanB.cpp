/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:24:44 by junguyen          #+#    #+#             */
/*   Updated: 2025/05/13 14:27:26 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::~HumanB( void ) {
}

HumanB::HumanB( std::string name) : _name( name ){
	_weapon = NULL;
}

void	HumanB::attack( void ) const {
	std::cout << _name << " attacks with their ";
	if (_weapon != NULL)
		std::cout << _weapon->getType();
	else
		std::cout << "*NO WEAPON*";
	std::cout << std::endl;
}

void	HumanB::setWeapon( Weapon &new_weapon ){
	_weapon = &new_weapon;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:24:44 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/10 14:40:20 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::~HumanA( void )
{
}

HumanA::HumanA( std::string name, Weapon &weapon) : _name( name ), _weapon( weapon )
{
}

void	HumanA::attack( void ) const
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
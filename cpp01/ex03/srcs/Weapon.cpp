/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:24:44 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/10 14:40:47 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( void )
{
}

Weapon::~Weapon( void )
{
}

Weapon::Weapon(std::string _name) : _type( _name )
{
}

std::string	Weapon::getType( void ) const
{
	return (_type);
}

void	Weapon::setType( std::string new_type )
{
	_type = new_type;
}
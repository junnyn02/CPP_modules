/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:56:20 by junguyen          #+#    #+#             */
/*   Updated: 2025/05/09 11:41:04 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void ) : _name("default") {
	return;
}

Zombie::Zombie( std::string name ) : _name(name) {
	return;
}

Zombie::~Zombie( void ) {
	std::cout << _name << " destroyed" << std::endl;
	return;
}

void	Zombie::announce( void ) const {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::newName( std::string name ){
	_name = name;
}
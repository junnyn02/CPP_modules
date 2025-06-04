/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:56:20 by junguyen          #+#    #+#             */
/*   Updated: 2025/04/28 18:08:39 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

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
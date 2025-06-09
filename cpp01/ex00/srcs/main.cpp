/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:49:45 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/09 16:22:17 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie zombie("Foo");
	zombie.announce();

	std::cout << "------------------------------" << std::endl;

	randomChump("zombie2");

	std::cout << "------------------------------" << std::endl;
	
	Zombie *newZ;
	newZ = newZombie("newZombie");
	newZ->announce();
	delete(newZ);
	
	return (0);
}
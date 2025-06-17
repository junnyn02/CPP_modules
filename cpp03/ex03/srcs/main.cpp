/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:49:45 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/17 15:05:02 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main( void )
{
	ScavTrap	ST("ScavTrap");

	std::cout << std::endl << "--------------------------------" << std::endl << std::endl;
	std::cout << ST;
	std::cout << std::endl << "--------------------------------" << std::endl << std::endl;
	
	FragTrap	FT("FragTrap");
	
	std::cout << std::endl << "--------------------------------" << std::endl << std::endl;
	std::cout << FT;
	std::cout << std::endl << "--------------------------------" << std::endl << std::endl;

	DiamondTrap	DT("DiamondTrap");
	
	std::cout << std::endl << "--------------------------------" << std::endl << std::endl;
	std::cout << DT;
	std::cout << std::endl << "--------------------------------" << std::endl << std::endl;

	DT.attack("GentilHeros");
	DT.takeDamage(2);
	DT.beRepaired(1);
	DT.whoAmI();
	
	std::cout << std::endl << "--------------------------------" << std::endl << std::endl;
	std::cout << DT;
	std::cout << std::endl << "--------------------------------" << std::endl << std::endl;

	return (0);
}

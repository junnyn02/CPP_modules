/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:49:45 by junguyen          #+#    #+#             */
/*   Updated: 2025/05/22 14:51:03 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main( void )
{
	ClapTrap	Vilain("MechantMechant");
	ScavTrap	Mechant("DarkMechant");

	std::cout << std::endl << "--------------------------------" << std::endl << std::endl;
	std::cout << Vilain;
	std::cout << std::endl << "--------------------------------" << std::endl << std::endl;

	Vilain.attack("GentilHeros");
	Vilain.takeDamage(2);
	Vilain.beRepaired(1);
	
	std::cout << std::endl << "--------------------------------" << std::endl << std::endl;
	std::cout << Vilain;
	std::cout << std::endl << "--------------------------------" << std::endl << std::endl;

	std::cout << std::endl << "--------------------------------" << std::endl << std::endl;
	std::cout << Mechant;
	std::cout << std::endl << "--------------------------------" << std::endl << std::endl;

	Mechant.attack("GentilHeros");
	Mechant.takeDamage(10);
	Mechant.beRepaired(3);
	Mechant.guardGate();

	std::cout << std::endl << "--------------------------------" << std::endl << std::endl;
	std::cout << Mechant;
	std::cout << std::endl << "--------------------------------" << std::endl << std::endl;
	
	return (0);
}

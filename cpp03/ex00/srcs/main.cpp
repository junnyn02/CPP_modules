/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:49:45 by junguyen          #+#    #+#             */
/*   Updated: 2025/05/21 17:58:46 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap Vilain("MechantMechant");

	std::cout << std::endl << "--------------------------------" << std::endl << std::endl;
	std::cout << Vilain;
	std::cout << std::endl << "--------------------------------" << std::endl << std::endl;

	Vilain.attack("GentilHeros");
	Vilain.takeDamage(2);
	Vilain.beRepaired(1);
	
	std::cout << std::endl << "--------------------------------" << std::endl << std::endl;
	std::cout << Vilain;
	std::cout << std::endl << "--------------------------------" << std::endl << std::endl;
	return (0);
}

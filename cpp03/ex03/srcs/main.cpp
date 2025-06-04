/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:49:45 by junguyen          #+#    #+#             */
/*   Updated: 2025/05/22 14:52:52 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main( void )
{
	DiamondTrap	DoubleFace("DoubleFace");

	std::cout << std::endl << "--------------------------------" << std::endl << std::endl;
	std::cout << DoubleFace;
	std::cout << std::endl << "--------------------------------" << std::endl << std::endl;

	DoubleFace.attack("GentilHeros");
	DoubleFace.takeDamage(2);
	DoubleFace.beRepaired(1);
	DoubleFace.whoAmI();
	
	std::cout << std::endl << "--------------------------------" << std::endl << std::endl;
	std::cout << DoubleFace;
	std::cout << std::endl << "--------------------------------" << std::endl << std::endl;

	return (0);
}

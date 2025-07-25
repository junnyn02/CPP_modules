/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:49:45 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/09 16:24:06 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie zombie("Zombie 1");
	zombie.announce();

	std::cout << "------------------------------" << std::endl;
	
	int N = 42;
	Zombie *newZ = zombieHorde( N, "horde");
	for (int i = 0; i < N; i++)
	{
		std::cout << i + 1 << " : ";
		newZ[i].announce();
	}
	delete [] newZ;
	return (0);
}
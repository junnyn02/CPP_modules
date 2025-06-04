/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:24:12 by junguyen          #+#    #+#             */
/*   Updated: 2025/05/09 11:43:17 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde ( int N, std::string name ) {
	Zombie *newZombie = new Zombie[N];
	
	for (int i = 0; i < N; i++)
		newZombie[i].newName(name);
	return ( newZombie );
}
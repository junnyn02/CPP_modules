/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:51:54 by junguyen          #+#    #+#             */
/*   Updated: 2025/05/09 11:38:56 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {

	private:
		std::string _name;
	public:
		Zombie( void );
		Zombie( std::string name );
		~Zombie( void );
		void	announce( void ) const;
		void	newName( std::string name);
};

Zombie*	zombieHorde ( int N, std::string name );

#endif
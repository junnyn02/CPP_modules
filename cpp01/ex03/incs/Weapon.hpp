/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:19:39 by junguyen          #+#    #+#             */
/*   Updated: 2025/05/13 14:08:54 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
// # include "HumanA.hpp"

class Weapon {

	private:
		std::string _type;
	public:
		Weapon( void );
		Weapon( std::string name );
		~Weapon( void );
		std::string	getType( void ) const;
		void	setType( std::string new_type );
};

#endif
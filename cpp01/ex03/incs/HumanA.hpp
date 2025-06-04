/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:19:39 by junguyen          #+#    #+#             */
/*   Updated: 2025/05/13 14:27:01 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA {

	private:
		std::string _name;
		Weapon	&_weapon;
	public:
		HumanA( std::string name, Weapon &weapon );
		~HumanA( void );
		void	attack( void ) const;
};

#endif
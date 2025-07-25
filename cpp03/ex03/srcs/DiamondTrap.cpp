/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/05/22 13:55:50 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap()
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	this->_name = ("Default_clap_name");
	FragTrap::setDefaultHP();
	ScavTrap::setDefaultEP();
	FragTrap::setDefaultAD();
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	std::cout << "DiamondTrap Named constructor called" << std::endl;
	FragTrap::setDefaultHP();
	ScavTrap::setDefaultEP();
	FragTrap::setDefaultAD();
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}


DiamondTrap::DiamondTrap(DiamondTrap const & cpy)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	*this = cpy;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & assign)
{
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	if (this != &assign)
	{
		this->_name = assign.getName();
		this->_hitPoints = assign.getHitPoints();
		this->_energyPoints = assign.getEnergyPoints();
		this->_attackDamage = assign.getAttackDamage();
	}
	return *this;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) const
{
	std::cout << "I'm " << this->_name << " also known as "<< ClapTrap::_name  << std::endl;
}


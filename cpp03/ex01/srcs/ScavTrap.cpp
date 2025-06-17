/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/16 15:55:07 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_guardGate = false;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap (name)
{
	std::cout << "ScavTrap named constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_guardGate = false;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}


ScavTrap::ScavTrap(ScavTrap const & cpy)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = cpy;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & assign)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if (this != &assign)
	{
		this->_name = assign.getName();
		this->_hitPoints = assign.getHitPoints();
		this->_energyPoints = assign.getEnergyPoints();
		this->_attackDamage = assign.getAttackDamage();
	}
	return *this;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " don't have enough Energy Points" << std::endl; 
		return ;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap <ScavTrap> " << this->_name << " attacks " << target << ", causing ";
	std::cout << this->_attackDamage << " points of damage" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
	this->_guardGate =  true;
}


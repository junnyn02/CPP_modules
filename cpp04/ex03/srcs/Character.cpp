/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/20 13:31:11 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : _name("Default")
{
	if (MSG)
		std::cout << "Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		_drop[i] = NULL;
}

Character::Character(std::string const & name) : _name(name)
{
	if (MSG)
		std::cout << "Character Named constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		_drop[i] = NULL;
}

Character::~Character(void)
{
	if (MSG)
		std::cout << "Character Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
		{
			delete (this->_inventory[i]);
			this->_inventory[i] = NULL;
		}
	}
	for (int i = 0; i < 100; i++)
	{
		if (this->_drop[i])
		{
			delete this->_drop[i];
			_drop[i] = NULL;
		}
	}
}

Character::Character(Character const & cpy)
{
	if (MSG)
		std::cout << "Character copy constructor called" << std::endl;
	*this = cpy;
}

Character & Character::operator=(Character const & assign)
{
	if (MSG)
		std::cout << "Character copy assignment operator called" << std::endl;
	if (this != &assign)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete (this->_inventory[i]);
		}
		for (int i = 0; i < 4; i++)
		{
			if (assign._inventory[i])
				this->_inventory[i] = assign._inventory[i]->clone();
		}
		for (int i = 0; i < 100; i++)
		{
			if (this->_drop[i])
				delete (this->_drop[i]);
		}
		for (int i = 0; i < 100; i++)
		{
			if (assign._drop[i])
				this->_drop[i] = assign._drop[i]->clone();
		}
		this->_name = assign.getName();
	}
	return *this;
}

std::string const&	Character::getName(void) const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	int	i = 0;

	if (!m)
		return ((void)(std::cout << "Materia dosen't exist" << std::endl));
	while (_inventory[i] != NULL)
		i++;
	if (i == 4)
	{
		while (i < 100)
		{
			if (!this->_drop[i])
			{
				this->_drop[i] = m;
				break ;
			}
			i++;
		}
		if (i == 100)
		{
			std::cout << "Drop full" << std::endl;
			return ;
		}
		return ((void)(std::cout << "Inventory is full" << std::endl));
	}
	else
	{
		for (int i = 0; i < 100; i++)
		{
			if (m == this->_drop[i])
				this->_drop[i] = NULL;
		}
		std::cout << "* " << this->getName() << " equip " << m->getType() << " *" << std::endl;
		this->_inventory[i] = m;
	}
}

void	Character::unequip(int idx)
{
	int i = 0;

	if (idx >= 4 || idx < 0 || this->_inventory[idx] == NULL)
		return ((void)(std::cout << "No Materia equiped at this index" << std::endl));
	else
	{
		std::cout << "* " << this->getName() << " unequip " << this->_inventory[idx]->getType() << " *" << std::endl;
		while (i < 100)
		{
			if (!this->_drop[i])
			{
				this->_drop[i] = this->_inventory[idx];
				break ;
			}
			i++;
		}
		if (i == 100)
		{
			std::cout << "Drop full" << std::endl;
			return ;
		}
		this->_inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx >= 4 || idx < 0 || this->_inventory[idx] == NULL)
		return ((void)(std::cout << "No Materia equiped at this index" << std::endl));
	this->_inventory[idx]->use(target);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/04 14:33:31 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) : _name("Default")
{
	std::cout << "Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character( std::string const & name ) : _name(name)
{
	std::cout << "Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::~Character( void )
{
	std::cout << "Character Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete (this->_inventory[i]);
	}
}

Character::Character( Character const & cpy )
{
	std::cout << "Character copy constructor called" << std::endl;
	*this = cpy;
}

Character & Character::operator=( Character const & assign )
{
	std::cout << "Character copy assignment operator called" << std::endl;
	if (this != &assign)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete (this->_inventory[i]);
		}
		for (int i = 0; i < 4; i++)
			this->_inventory[i] = assign._inventory[i];
		this->_name = assign.getName();
	}
	return *this;
}

std::string const&	Character::getName( void ) const
{
	return ( this->_name );
}

void	Character::equip( AMateria *m)
{
	int	i = 0;

	if (!m)
		return ((void)(std::cout << "Materia dosen't exist" << std::endl));
	while (_inventory[i] != NULL)
		i++;
	if (i == 4)
		return ((void)(std::cout << "Inventory is full" << std::endl));
	else
		this->_inventory[i] = m;
}

void	Character::unequip( int idx )
{
	if ( idx >= 4 || idx < 0 || this->_inventory[idx] == NULL)
		return ((void)(std::cout << "No Materia equiped at this index" << std::endl));
	else
		this->_inventory[idx] = NULL;
}

void	Character::use( int idx, ICharacter &target )
{
	if ( idx >= 4 || idx < 0 || this->_inventory[idx] == NULL)
		return ((void)(std::cout << "No Materia equiped at this index" << std::endl));
	this->_inventory[idx]->use(target);
}
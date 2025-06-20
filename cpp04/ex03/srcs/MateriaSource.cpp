/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/20 13:29:17 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	if (MSG)
		std::cout << "MateriaSource constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_stock[i] = NULL;
}

MateriaSource::~MateriaSource(void)
{
	if (MSG)
		std::cout << "MateriaSource Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_stock[i])
			delete (this->_stock[i]);
	}
}

MateriaSource::MateriaSource(MateriaSource const & cpy)
{
	if (MSG)
		std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = cpy;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & assign)
{
	if (MSG)
		std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this != &assign)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_stock[i])
				delete (this->_stock[i]);
		}
		for (int i = 0; i < 4; i++)
			this->_stock[i] = assign._stock[i]->clone();
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria *toLearn)
{
	int	idx = 0;

	while(idx < 4 && this->_stock[idx] != NULL)
		idx++;
	if (idx == 4)
	{
		delete toLearn;
		return ((void)(std::cout << "Can't learn more Materia" << std::endl));
	}
	std::cout << "New Materia Learn" << std::endl;
	_stock[idx] = toLearn;
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
	int	idx = 0;

	while(idx < 4)
	{
		if (this->_stock[idx] && this->_stock[idx]->getType() == type)
			break ;
		idx++;
	}
	if (idx == 4)
	{
		std::cout << "Unknown type" << std::endl;
		return (0);
	}
	std::cout << "New Materia created" << std::endl;
	return (this->_stock[idx]->clone());
}

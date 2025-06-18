/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ground.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/18 17:50:46 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ground.hpp"

Ground::Ground(void)
{
	std::cout << "Ground constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_drop[i] = NULL;
}

Ground::~Ground(void)
{
	std::cout << "Ground Destructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		delete _drop[i];
}

Ground::Ground(Ground const & cpy)
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this = cpy;
}

Ground & Ground::operator=(Ground const & assign)
{
	std::cout << "Cure copy assignment operator called" << std::endl;
	if (this != &assign)
	{
		for (int i = 0; i < 100; i++)
		{
			if (this->_drop[i])
				delete (this->_drop[i]);
		}
		for (int i = 0; i < 100; i++)
			this->_drop[i] = assign._drop[i];
	}
	return *this;
}

void	Ground::add(AMateria * unequip)
{
	for (int i = 0; i < 100; i++)
	{
		if (this->_drop[i] == NULL)
		{
			this->_drop[i] = unequip;
			break ;
		}
	}
}
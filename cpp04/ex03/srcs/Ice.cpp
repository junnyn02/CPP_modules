/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/19 14:10:09 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	if (MSG)
		std::cout << "Ice constructor called" << std::endl;
}

Ice::~Ice(void)
{
	if (MSG)
		std::cout << "Ice Destructor called" << std::endl;
}

Ice::Ice(Ice const & cpy)
{
	if (MSG)
		std::cout << "Cure copy constructor called" << std::endl;
	*this = cpy;
}

Ice & Ice::operator=(Ice const & assign)
{
	if (MSG)
		std::cout << "Cure copy assignment operator called" << std::endl;
	if (this != &assign)
		this->_type = assign.getType();
	return *this;
}

AMateria*	Ice::clone(void) const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target)
{
	std::cout << "Ice : \"* shoots an ice bolt at " << target.getName();
	std::cout << " *\"" << std::endl;
}

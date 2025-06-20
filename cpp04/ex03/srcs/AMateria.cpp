/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/19 14:09:54 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("Default")
{
	if (MSG)
		std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	if (MSG)
		std::cout << "AMateria _type constructor called" << std::endl;
}

AMateria::~AMateria(void)
{
	if (MSG)
		std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria(AMateria const & cpy)
{
	if (MSG)
		std::cout << "AMateria copy constructor called" << std::endl;
	*this = cpy;
}

AMateria & AMateria::operator=(AMateria const & assign)
{
	if (MSG)
		std::cout << "AMateria copy assignment operator called" << std::endl;
	if (this != &assign)
		this->_type = assign.getType();
	return *this;
}

std::string const&	AMateria::getType(void) const
{
	return (this->_type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "Default : \"* use power on " << target.getName();
	std::cout << " *\"" << std::endl;
}

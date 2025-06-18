/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/18 12:28:42 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("Animal")
{
	std::cout << "AAnimal Default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string const & type) : _type(type)
{
	std::cout << "AAnimal Default constructor called" << std::endl;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal Destructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const & cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

AAnimal & AAnimal::operator=(AAnimal const & assign)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &assign)
		this->_type = assign.getType();
	return *this;
}

const std::string &	AAnimal::getType(void) const
{
	return (this->_type);
}

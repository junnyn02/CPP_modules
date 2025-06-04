/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/05/27 15:18:00 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal( void ) : _type( "Animal" )
{
	std::cout << "Default constructor called" << std::endl;
}

AAnimal::AAnimal( std::string type ) : _type( type )
{
	std::cout << "Default constructor called" << std::endl;
}

AAnimal::~AAnimal( void )
{
	std::cout << "Destructor called" << std::endl;
}

AAnimal::AAnimal( AAnimal const & cpy )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

AAnimal & AAnimal::operator=( AAnimal const & assign )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &assign)
		this->_type = assign.getType();
	return *this;
}

std::string	AAnimal::getType( void ) const
{
	return (this->_type);
}

void	AAnimal::makeSound( void ) const
{
	std::cout << "**" << std::endl;
}

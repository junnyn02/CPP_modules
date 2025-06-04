/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/05/22 16:10:07 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type( "WrongAnimal" )
{
	std::cout << "Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : _type( type )
{
	std::cout << "Default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const & cpy )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

WrongAnimal & WrongAnimal::operator=( WrongAnimal const & assign )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &assign)
		this->_type = assign.getType();
	return *this;
}

std::string	WrongAnimal::getType( void ) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "**" << std::endl;
}

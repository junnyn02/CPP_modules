/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/05/22 15:59:49 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : _type( "Animal" )
{
	std::cout << "Default constructor called" << std::endl;
}

Animal::Animal( std::string type ) : _type( type )
{
	std::cout << "Default constructor called" << std::endl;
}

Animal::~Animal( void )
{
	std::cout << "Destructor called" << std::endl;
}

Animal::Animal( Animal const & cpy )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Animal & Animal::operator=( Animal const & assign )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &assign)
		this->_type = assign.getType();
	return *this;
}

std::string	Animal::getType( void ) const
{
	return (this->_type);
}

void	Animal::makeSound( void ) const
{
	std::cout << "**" << std::endl;
}

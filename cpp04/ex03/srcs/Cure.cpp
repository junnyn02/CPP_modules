/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/03 14:32:16 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure")
{
	std::cout << "Cure constructor called" << std::endl;
}

Cure::~Cure( void )
{
	std::cout << "Cure Destructor called" << std::endl;
}

Cure::Cure( Cure const & cpy )
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this = cpy;
}

Cure & Cure::operator=( Cure const & assign )
{
	std::cout << "Cure copy assignment operator called" << std::endl;
	if (this != &assign)
		this->_type = assign.getType();
	return *this;
}

std::string const&	Cure::getType( void ) const
{
	return ( this->_type );
}

AMateria*	Cure::clone( void ) const
{
	return (new Cure(*this));
}

void	Cure::use( ICharacter &target )
{
	std::cout << "Cure : \"* heals " << target.getName();
	std::cout << "'s wounds *\"" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/05/22 16:30:18 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog")
{
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::~Dog( void )
{
	std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog( Dog const & cpy )
{
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = cpy;
}

Dog & Dog::operator=( Dog const & assign )
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &assign)
		this->_type = assign.getType();
	return *this;
}

void	Dog::makeSound( void ) const
{
	std::cout << "Wouf" << std::endl;
}

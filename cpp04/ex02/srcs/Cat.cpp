/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/05/27 15:17:29 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat( void ) : AAnimal("Cat")
{
	std::cout << "Cat Default constructor called" << std::endl;
	_brain = new Brain();
}

Cat::~Cat( void )
{
	delete _brain;
	std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat( Cat const & cpy )
{
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = cpy;
}

Cat & Cat::operator=( Cat const & assign )
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &assign)
	{
		this->_type = assign.getType();
		this->_brain = new Brain(*assign._brain);
	}
	return *this;
}

void	Cat::makeSound( void ) const
{
	std::cout << "Miaou" << std::endl;
}

void	Cat::getIdea( int index ) const
{
	return this->_brain->getIdea(index);
}

void	Cat::setIdea( int index, std::string idea )
{
	return this->_brain->setIdea( index, idea );
}

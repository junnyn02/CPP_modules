/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/17 18:54:06 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog Default constructor called" << std::endl;
	_brain = new Brain();
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(Dog const & cpy)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = cpy;
}

Dog & Dog::operator=(Dog const & assign)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &assign)
	{
		this->_type = assign.getType();
		this->_brain = new Brain(*assign._brain);
	}
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "Wouf" << std::endl;
}

void	Dog::getIdea(int index) const
{
	return this->_brain->getIdea(index);
}

void	Dog::setIdea(int index, std::string idea)
{
	return this->_brain->setIdea(index, idea);
}
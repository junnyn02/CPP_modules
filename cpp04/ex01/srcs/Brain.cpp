/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/05/22 17:23:02 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::~Brain( void )
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain( Brain const & cpy )
{
	std::cout << "Brain Copy constructor called" << std::endl;
	*this = cpy;
}

Brain & Brain::operator=( Brain const & assign )
{
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if (this != &assign)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = assign._ideas[i];
	}
		return (*this);
	return *this;
}

void	Brain::setIdea( int index, std::string idea )
{
	if (index > 99)
		std::cout << "Index is out of bounds" << std::endl;
	else
		this->_ideas[index] = idea;
}

void	Brain::getIdea( int index ) const
{
	if (index > 99)
		std::cout << "Index is out of bounds" << std::endl;
	else
		std::cout << this->_ideas[index] << std::endl;
}
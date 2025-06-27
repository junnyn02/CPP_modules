/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/27 15:52:59 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
	if (MSG)
		std::cout << "Serializer constructor called" << std::endl;
}

Serializer::~Serializer(void)
{
	if (MSG)
		std::cout << "Serializer Destructor called" << std::endl;
}

Serializer::Serializer(Serializer const & cpy)
{
	if (MSG)
		std::cout << "Serializer copy constructor called" << std::endl;
	*this = cpy;
}

Serializer & Serializer::operator=(Serializer const & assign)
{
	if (MSG)
		std::cout << "Serializer copy assignment operator called" << std::endl;
	(void)assign;
	return *this;
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}


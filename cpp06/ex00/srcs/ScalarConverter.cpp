/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/24 18:58:15 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	if (MSG)
		std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter(void)
{
	if (MSG)
		std::cout << "ScalarConverter Destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const & cpy)
{
	if (MSG)
		std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = cpy;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & assign)
{
	if (MSG)
		std::cout << "ScalarConverter copy assignment operator called" << std::endl;
	(void)assign;
	return *this;
}


void ScalarConverter::convert(std::string const & to_convert)
{
	find_type(to_convert);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/27 15:52:59 by junguyen         ###   ########.fr       */
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
	if (is_char(to_convert))
		convert_char(to_convert);
	else if (is_int(to_convert))
		convert_int(to_convert);
	else if (is_float(to_convert))
		convert_float(to_convert);
	else if (is_double(to_convert))
		convert_double(to_convert);
	else if (is_special(to_convert))
		print_special_msg(to_convert);
	else
		std::cout << "Error: Unknown type" << std::endl;
}
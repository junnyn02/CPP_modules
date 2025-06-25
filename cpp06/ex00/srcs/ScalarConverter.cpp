/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/25 15:50:51 by junguyen         ###   ########.fr       */
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

void	convert_float(std::string const & to_convert)
{
	float f = atof(to_convert.c_str());
	double d = static_cast<double>(f);
	
	if (f > CHAR_MAX || f < CHAR_MIN)
		std::cout << "char: impossible" << std::endl;
	else
	{
		char c = static_cast<char>(f);
		std::cout << "char: ";
		if (!isprint(c))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << c << std::endl;
	}
	if (static_cast<long>(f) > INT_MAX || static_cast<long>(f) < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
	{
		int i = static_cast<int>(f);
		std::cout << "int: " << i << std::endl;
	}
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

void	convert_int(std::string const & to_convert)
{
	int i = atoi(to_convert.c_str());
	double d = static_cast<double>(i);
	float f = static_cast<float>(i);
	
	if (i > CHAR_MAX || i < CHAR_MIN)
		std::cout << "char: impossible" << std::endl;
	else
	{
		char c = static_cast<char>(i);
		std::cout << "char: ";
		if (!isprint(c))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << c << std::endl;
	}
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

void	convert_char(std::string const & to_convert)
{
	char c = static_cast<char>(to_convert[0]);
	int i = static_cast<int>(c);
	double d = static_cast<double>(c);
	float f = static_cast<float>(c);
	
	std::cout << "char: ";
	if (!isprint(c))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

bool	is_float(std::string const & to_convert)
{
	// if (to_convert == "nanf")
	// 	return (true);
	std::size_t	found = to_convert.find(".");
	if (found == std::string::npos)
		return (false);
	std::string::const_iterator it = to_convert.end();
	if (*--it != 'f')
		return (false);
	std::string::const_iterator a = to_convert.begin(); 
	if (*a == '+' || *a == '-')
		a++;
	while (*a != '.')
	{
		if (!isdigit(*a))
			return(false);
		a++;	
	}
	a++;
	while (a != it)
	{
		if (!isdigit(*a))
			return(false);
		a++;	
	}
	// std::cout << atof(to_convert.c_str()) << std::endl;
	return (true);
}

bool	is_int(std::string const & to_convert)
{
	int i = 0;
	if (to_convert[0] == '+' || to_convert[0] == '-')
		i++;
	while (to_convert[i])
	{
		if (!isdigit(to_convert[i]))
			return (false);
		i++;
	}
	double n = atol(to_convert.c_str());
	if (n > INT_MAX || n < INT_MIN)
		return (false);
	return (true);
}

bool	is_char(std::string const & to_convert)
{
	if (to_convert.length() == 1 && !isdigit(to_convert[0]))
		return (true);
	return (false);
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
		std::cout << "unknown type" << std::endl;
}
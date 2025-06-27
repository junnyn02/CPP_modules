#include "ScalarConverter.hpp"

bool	is_special(std::string const &to_convert)
{
	if (to_convert == "+inf" || to_convert == "+inff" || to_convert == "-inf" || to_convert == "-inff" || to_convert == "nan" || to_convert == "nanf")
		return (true);
	return (false);
}

bool	is_double(std::string const & to_convert)
{
	std::size_t	found = to_convert.find(".");
	if (found == std::string::npos)
		return (false);
	std::string::const_iterator it = to_convert.end();
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
	return (true);
}

bool	is_float(std::string const & to_convert)
{
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
	return (true);
}

bool	is_int(std::string const & to_convert)
{
	int i = 0;
	while (isspace(to_convert[i]))
		i++;
	if (to_convert[i] == '+' || to_convert[i] == '-')
		i++;
	while (to_convert[i])
	{
		if (!isdigit(to_convert[i]) && !isspace(to_convert[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	is_char(std::string const & to_convert)
{
	if (to_convert.length() == 1 && !isdigit(to_convert[0]))
		return (true);
	return (false);
}
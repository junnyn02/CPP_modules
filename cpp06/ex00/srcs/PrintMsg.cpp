#include "ScalarConverter.hpp"

void	print_special_msg(std::string const &to_convert)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: ";
	if (to_convert == "+inff" || to_convert == "-inff" || to_convert == "nanf")
		std::cout << to_convert << std::endl;
	else
		std::cout << to_convert << "f" << std::endl;
	std::cout << "double: ";
	if (to_convert == "+inf" || to_convert == "-inf" || to_convert == "nan")
		std::cout << to_convert << std::endl;
	else
	{
		char buffer[5];
		to_convert.copy(buffer, to_convert.length() - 1, 0);
		buffer[to_convert.length() - 1] = '\0';
		std::cout << buffer << std::endl;
	}
}

void	convert_double(std::string const & to_convert)
{
	double d = strtod(to_convert.c_str(), NULL);
	if (errno == ERANGE && d < std::numeric_limits<double>::min())
	{
		std::cout << "Error: Underflow" << std::endl;
		return ;
	}
	if (errno == ERANGE && d > std::numeric_limits<double>::max())
	{
		std::cout << "Error: Overflow" << std::endl;
		return ;
	}
	if (d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min())
		std::cout << "char: impossible" << std::endl;
	else
	{
		char c = static_cast<char>(d);
		std::cout << "char: ";
		if (!isprint(c))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << c << std::endl;
	}
	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
	std::cout << "int: impossible" << std::endl;
	else
	{
		int i = static_cast<int>(d);
		std::cout << "int: " << i << std::endl;
	}
	if (d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::min())
	std::cout << "float: impossible" << std::endl;
	else
	{
		float f = static_cast<float>(d);
		std::cout << "float: " << f << std::endl;
	}
	std::cout << "double: " << d << std::endl;
}

void	convert_float(std::string const & to_convert)
{
	float f = strtof(to_convert.c_str(), NULL);
	if (errno == ERANGE && f < std::numeric_limits<float>::min())
	{
		std::cout << "Error: Underflow" << std::endl;
		return ;
	}
	if (errno == ERANGE && f > std::numeric_limits<float>::max())
	{
		std::cout << "Error: Overflow" << std::endl;
		return ;
	}
	if (f > std::numeric_limits<char>::max() || f < std::numeric_limits<char>::min())
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
	if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
	std::cout << "int: impossible" << std::endl;
	else
	{
		int i = static_cast<int>(f);
		std::cout << "int: " << i << std::endl;
	}
	std::cout << "float: " << f << "f" << std::endl;
	double d = static_cast<double>(f);
	std::cout << "double: " << d << std::endl;
}

void	convert_int(std::string const & to_convert)
{
	long l = strtol(to_convert.c_str(), NULL, 10);
	if (l < std::numeric_limits<int>::min())
	{
		std::cout << "Error: Underflow" << std::endl;
		return ;
	}
	if (l > std::numeric_limits<int>::max())
	{
		std::cout << "Error: Overflow" << std::endl;
		return ;
	}
	int i = static_cast<int>(l);
	if (i > std::numeric_limits<char>::max() || i < std::numeric_limits<char>::min())
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
	double d = static_cast<double>(i);
	float f = static_cast<float>(i);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
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
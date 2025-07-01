/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:16 by junguyen          #+#    #+#             */
/*   Updated: 2025/07/01 13:42:05 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <stdlib.h>
# include <errno.h>
# include <limits>

# ifndef MSG
#	define MSG 1
# endif

class	ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const & cpy);
		~ScalarConverter(void);
		ScalarConverter &	operator=(ScalarConverter const & assign);
	
	public:
		static void convert(std::string const &);
};

void	print_special_msg(std::string const &to_convert);
void	convert_double(std::string const & to_convert);
void	convert_float(std::string const & to_convert);
void	convert_int(std::string const & to_convert);
void	convert_char(std::string const & to_convert);

bool	is_special(std::string const &to_convert);
bool	is_double(std::string const &to_convert);
bool	is_float(std::string const &to_convert);
bool	is_int(std::string const &to_convert);
bool	is_char(std::string const &to_convert);

#endif
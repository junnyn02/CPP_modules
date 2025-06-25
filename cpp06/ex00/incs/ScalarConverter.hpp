/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:16 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/25 15:14:46 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include <stdlib.h>
# include <limits.h>

# ifndef MSG
#	define MSG 1
# endif

// #define __STDC_LIMIT_MACROS
// #include <stdint.h>


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

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:49:45 by junguyen          #+#    #+#             */
/*   Updated: 2025/05/09 12:15:28 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int	main( void )
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Memory adress of str : " << &str << std::endl;
	std::cout << "Memory adress held by stringPTR : " << stringPTR << std::endl;
	std::cout << "Memory adress held by stringREF : " << &stringREF << std::endl;

	std::cout << "---------------------------------------------------------------" << std::endl;
	
	std::cout << "Value of str : " << str << std::endl;
	std::cout << "Value pointed to by stringPTR : " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF : " << stringREF << std::endl;
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:05:08 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/20 14:08:19 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat	Bob("Bob", 152);
	std::cout << Bob;

	Bureaucrat	Patrick("Patrick", 150);
	std::cout << Patrick;
	Patrick.decrementGrade();
	std::cout << Patrick;

	Bureaucrat	Boss("Boss", 2);
	std::cout << Boss;
	Boss.incrementGrade();
	std::cout << Boss;
	Boss.incrementGrade();
	std::cout << Boss;

	Form	*ptr;
	try
	{
		ptr = new Form("Contract", 1, 1);
		Patrick.signForm(*ptr);
		Boss.signForm(*ptr);
		std::cout << *ptr;
		Bureaucrat	Vice("Vice Pres", 2);
		Vice.signForm(*ptr);
		delete ptr;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
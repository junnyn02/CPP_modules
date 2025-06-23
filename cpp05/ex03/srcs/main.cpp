/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:05:08 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/23 11:31:04 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << "---------------------------ShrubberyCreationForm---------------------------" << std::endl;
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		std::cout << *rrf;
		
		Bureaucrat Pierre("Pierre", 137);
		Pierre.signForm(*rrf);
		Pierre.executeForm(*rrf);

		delete rrf;
	}
	std::cout << "---------------------------------------------------------------------------" << std::endl;
	std::cout << "-----------------------------RobotomyRequestForm---------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------------------" << std::endl;
	std::cout << "---------------------------PresidentialPardonForm--------------------------" << std::endl;
	return 0;
}
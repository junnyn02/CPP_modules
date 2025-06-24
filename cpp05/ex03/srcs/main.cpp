/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:05:08 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/24 14:35:57 by junguyen         ###   ########.fr       */
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
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf;
		
		Bureaucrat Pierre("Pierre", 137);
		std::cout << Pierre;
		Pierre.signForm(*rrf);
		Pierre.executeForm(*rrf);
		Bureaucrat Bernard("Bernard", 6);
		std::cout << Bernard;
		Bernard.signForm(*rrf);
		Bernard.executeForm(*rrf);

		delete rrf;
	}
	std::cout << "---------------------------------------------------------------------------" << std::endl;
	std::cout << "---------------------------PresidentialPardonForm--------------------------" << std::endl;
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		std::cout << *rrf;
		
		Bureaucrat Pierre("Pierre", 137);
		std::cout << Pierre;
		Pierre.signForm(*rrf);
		Pierre.executeForm(*rrf);
		Bureaucrat Bernard("Bernard", 6);
		std::cout << Bernard;
		Bernard.signForm(*rrf);
		Bernard.executeForm(*rrf);

		delete rrf;
	}
	std::cout << "---------------------------------------------------------------------------" << std::endl;
	std::cout << "---------------------------Wrong request--------------------------" << std::endl;
	{
		AForm* rrf;
		try
		{
			Intern someRandomIntern;
			rrf = someRandomIntern.makeForm("wrong request", "Bender");
			std::cout << *rrf;
			Bureaucrat Pierre("Pierre", 137);
			Pierre.signForm(*rrf);
			Pierre.executeForm(*rrf);

			delete rrf;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		
	}
	return 0;
}
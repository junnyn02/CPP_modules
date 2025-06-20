/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:05:08 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/20 17:08:00 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "---------------------------ShrubberyCreationForm---------------------------" << std::endl;
	AForm *a = new ShrubberyCreationForm("target");
	std::cout << *a;
	Bureaucrat	Jacques("Jacques", 130);
	std::cout << Jacques;
	Jacques.signForm(*a);
	Jacques.executeForm(*a);
	Bureaucrat	Pierre("Pierre", 150);
	std::cout << Jacques;
	Pierre.signForm(*a);
	std::cout << "---------------------------------------------------------------------------" << std::endl;
	std::cout << "-----------------------------RobotomyRequestForm---------------------------" << std::endl;
	AForm *b = new RobotomyRequestForm("robot");
	std::cout << *b;
	std::cout << Jacques;
	Pierre.signForm(*b);
	Bureaucrat Paul("Paul", 70);
	Bureaucrat Bernard("Bernard", 6);
	std::cout << Paul;
	Paul.signForm(*b);
	Paul.executeForm(*b);
	std::cout << Bernard;
	Bernard.executeForm(*b);
	std::cout << "---------------------------------------------------------------------------" << std::endl;
	std::cout << "---------------------------PresidentialPardonForm--------------------------" << std::endl;
	AForm *c = new PresidentialPardonForm("me");
	std::cout << *c;
	Pierre.signForm(*c);
	Bernard.signForm(*c);
	Bernard.executeForm(*c);
	Bernard.incrementGrade();
	Bernard.executeForm(*c);
	
	delete a;
	delete b;
	delete c;
	// Bureaucrat	Bob("Bob", 152);
	// std::cout << Bob;

	// Bureaucrat	Patrick("Patrick", 150);
	// std::cout << Patrick;
	// Patrick.decrementGrade();
	// std::cout << Patrick;

	// Bureaucrat	Boss("Boss", 2);
	// std::cout << Boss;
	// Boss.incrementGrade();
	// std::cout << Boss;
	// Boss.incrementGrade();
	// std::cout << Boss;

	// Form a("Contract", 1, 1);
	// Patrick.signForm(a);

	// Boss.signForm(a);
	// Bureaucrat	Vice("Vice Pres", 2);
	// Vice.signForm(a);

	return 0;
}
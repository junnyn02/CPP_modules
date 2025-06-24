/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern copy.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/20 15:41:39 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	if (MSG)
		std::cout << "Inter constructor called" << std::endl;
}

Intern::~Intern(void)
{
	if (MSG)
		std::cout << "Intern Destructor called" << std::endl;
}

Intern::Intern(Intern const & cpy)
{
	if (MSG)
		std::cout << "Intern copy constructor called" << std::endl;
	*this = cpy;
}

Intern & Intern::operator=(Intern const & assign)
{
	if (MSG)
		std::cout << "Intern copy assignment operator called" << std::endl;
	(void)assign;
	return *this;
}

AForm *	Intern::makeForm(std::string const & name, std::string const & target)
{
	int i = 0;
	std::string const param[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *	(Intern::*fn_ptr[3])(std::string const & target) = {&Intern::returnShrubbery, &Intern::returnRobot, &Intern::returnPresident};
	AForm	*form;
	while (i < 4)
	{
		if (name == param[i])
		{
			form = (this->*fn_ptr[i])(target);
			break ;
		}
		i++;
	}
	if (i == 4)
		throw Intern::NameNotFound();
	std::cout << "Intern creates " << "form" << std::endl;
	return form;
}

AForm *	Intern::returnShrubbery(std::string const & target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *	Intern::returnRobot(std::string const & target)
{
	return (new RobotomyRequestForm(target));
}

AForm *	Intern::returnPresident(std::string const & target)
{
	return (new PresidentialPardonForm(target));
}

const char *Intern::NameNotFound::what(void) const throw()
{
	return ("Name Form not found");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/20 15:24:14 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", "NoTarget", 72, 45)
{
	if (MSG)
		std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : AForm("RobotomyRequestForm", target, 72, 45)
{
	if (MSG)
		std::cout << "RobotomyRequestForm name constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	if (MSG)
		std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & cpy) : AForm(cpy)
{
	if (MSG)
		std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = cpy;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & assign)
{
	if (MSG)
		std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	if (this != &assign)
		*this = assign;
	return *this;
}

void	RobotomyRequestForm::do_exec(void) const
{
	srand(time(0));
	bool	success = (rand() % 2) == 0;

	std::cout << "* DRILLING NOISES *" << std::endl;
	if (success)
		std::cout << this->getTarget() << " has been robotomized succesfully." << std::endl;
	else
		std::cout << "The robotomy failed." << std::endl;
}
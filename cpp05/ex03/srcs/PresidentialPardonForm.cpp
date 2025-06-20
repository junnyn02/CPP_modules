/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/20 14:32:37 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", "NoTarget", 25, 5)
{
	if (MSG)
		std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : AForm("PresidentialPardonForm", target, 25, 5)
{
	if (MSG)
		std::cout << "PresidentialPardonForm name constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	if (MSG)
		std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & cpy) : AForm(cpy)
{
	if (MSG)
		std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = cpy;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & assign)
{
	if (MSG)
		std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	if (this != &assign)
		*this = assign;
	return *this;
}

void	PresidentialPardonForm::do_exec(void) const
{
	std::cout << this->getTarget()<< " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

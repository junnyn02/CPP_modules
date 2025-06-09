/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/05 18:30:51 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("Default", 145, 137)
{
	if (MSG)
		std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const & name ) : AForm(name, 145, 137)
{
	if (MSG)
		std::cout << "ShrubberyCreationForm name constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	if (MSG)
		std::cout << "Form Destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & cpy ) : AForm(cpy)
{
	if (MSG)
		std::cout << "Form copy constructor called" << std::endl;
	*this = cpy;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & assign )
{
	if (MSG)
		std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &assign)
		*this = assign;
	return *this;
}

// std::ostream &	operator<<( std::ostream & o, ShrubberyCreationForm const &i )
// {
// 	o << i.getName() << ", Form need grade " << i.getGradeToSign() << " to sign and grade " << i.getGradeToSign() << " to exec.";
// 	if (i.getSigned()) 
// 		o << "Status : is signed" << std::endl;
// 	else
// 		o << "Status : isn't signed" << std::endl;
// 	return (o);
// }
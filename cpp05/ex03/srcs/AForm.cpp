/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/20 14:15:30 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("Default"), _target("NoTarget"),_signed(false), _grade_to_sign(150), _grade_to_exec(150)
{
	if (MSG)
		std::cout << "Form constructor called" << std::endl;
}

AForm::AForm(std::string const & name, std::string const & target,unsigned int grade_to_sign, unsigned int grade_to_exec) :
			_name(name), _target(target), _signed(false), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
	if (MSG)
		std::cout << "Form name constructor called" << std::endl;
	try
	{
		if (_grade_to_sign < 1 || _grade_to_exec < 1)
			throw AForm::GradeTooHighException();
		if (_grade_to_sign > 150 || _grade_to_exec > 150)
			throw AForm::GradeTooLowException();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << " Default grade applied." << std::endl;
	}
}

AForm::~AForm(void)
{
	if (MSG)
		std::cout << "Form Destructor called" << std::endl;
}

AForm::AForm(AForm const & cpy) : _grade_to_sign(cpy.getGradeToSign()), _grade_to_exec(cpy.getGradeToSign())
{
	if (MSG)
		std::cout << "Form copy constructor called" << std::endl;
	*this = cpy;
}

AForm & AForm::operator=(AForm const & assign)
{
	if (MSG)
		std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &assign)
		this->_signed = assign.getSigned();
	return *this;
}

std::string const&	AForm::getName(void) const
{
	return (this->_name);
}

std::string const&	AForm::getTarget(void) const
{
	return (this->_target);
}

unsigned int const&	AForm::getGradeToSign(void) const
{
	return (this->_grade_to_sign);
}

unsigned int const&	AForm::getGradeToExec(void) const
{
	return (this->_grade_to_exec);
}

bool const&	AForm::getSigned(void) const
{
	return (this->_signed);
}

void	AForm::beSigned(Bureaucrat const &bc)
{
	if (this->getSigned() == true)
		throw AForm::FormAlreadySigned();
	else if (bc.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
	else
		this->_signed = true;
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw AForm::FormNotSigned();
	if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();
	do_exec();
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade's too high.");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade's too low.");
}

const char *AForm::FormAlreadySigned::what(void) const throw()
{
	return ("Form is already signed.");
}

const char *AForm::FormNotSigned::what(void) const throw()
{
	return ("Form is not signed yet.");
}

std::ostream &	operator<<(std::ostream & o, AForm const &i)
{
	o << i.getName() << ", Form need grade " << i.getGradeToSign() << " to sign and grade " << i.getGradeToExec() << " to exec.";
	if (i.getSigned()) 
		o << " Status : is signed" << std::endl;
	else
		o << " Status : isn't signed" << std::endl;
	return (o);
}
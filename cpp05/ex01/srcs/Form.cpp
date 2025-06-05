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

#include "Form.hpp"

Form::Form( void ) : _name("Default"), _signed(false), _grade_to_sign(150), _grade_to_exec(150)
{
	if (MSG)
		std::cout << "Form constructor called" << std::endl;
}

Form::Form( std::string const & name, unsigned int grade_to_sign, unsigned int grade_to_exec ) :
			_name(name),  _signed(false), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
	if (MSG)
		std::cout << "Form name constructor called" << std::endl;
	try
	{
		if (_grade_to_sign < 1 || _grade_to_exec < 1)
			throw Form::GradeTooHighException();
		if (_grade_to_sign > 150 || _grade_to_exec > 150)
			throw Form::GradeTooLowException();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << " Default grade applied." << std::endl;
	}
}

Form::~Form( void )
{
	if (MSG)
		std::cout << "Form Destructor called" << std::endl;
}

Form::Form( Form const & cpy ) : _grade_to_sign(cpy.getGradeToSign()), _grade_to_exec(cpy.getGradeToSign())
{
	if (MSG)
		std::cout << "Form copy constructor called" << std::endl;
	*this = cpy;
}

Form & Form::operator=( Form const & assign )
{
	if (MSG)
		std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &assign)
		this->_signed = assign.getSigned();
	return *this;
}

std::string const&	Form::getName( void ) const
{
	return ( this->_name );
}

unsigned int const&	Form::getGradeToSign( void ) const
{
	return ( this->_grade_to_sign );
}

unsigned int const&	Form::getGradeToExec( void ) const
{
	return ( this->_grade_to_exec );
}

bool const&	Form::getSigned( void ) const
{
	return ( this->_signed );
}

bool	Form::beSigned( Bureaucrat const &bc )
{
	// if (this->getSigned())
	// {
	// 	std::cout << "Form is already signed";
	// 	return false;
	// }
	try
	{
		if (bc.getGrade() < this->getGradeToSign())
			throw Form::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return false;
	}
	this->_signed = true;
	return true;
}

const char *Form::GradeTooHighException::what( void ) const throw()
{
	return ("Grade's too high.");
}

const char *Form::GradeTooLowException::what( void ) const throw()
{
	return ("Grade's too low.");
}

std::ostream &	operator<<( std::ostream & o, Form const &i )
{
	o << i.getName() << ", Form need grade " << i.getGradeToSign() << " to sign and grade " << i.getGradeToSign() << " to exec.";
	if (i.getSigned()) 
		o << "Status : is signed" << std::endl;
	else
		o << "Status : isn't signed" << std::endl;
	return (o);
}
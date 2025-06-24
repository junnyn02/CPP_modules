/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/24 14:11:12 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("Default"), _grade(150)
{
	if (MSG)
		std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( std::string const & name, unsigned int grade ) : _name(name)
{
	if (MSG)
		std::cout << "Bureaucrat name constructor called" << std::endl;
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		_grade = grade;
	}
	catch (const Bureaucrat::GradeTooHighException & e)
	{
		std::cerr << e.what() << " Default grade applied." << std::endl;
		_grade = 150;
	}
	catch (const Bureaucrat::GradeTooLowException & e)
	{
		std::cerr << e.what() << " Default grade applied." << std::endl;
		_grade = 150;
	}
}

Bureaucrat::~Bureaucrat( void )
{
	if (MSG)
		std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat( Bureaucrat const & cpy )
{
	if (MSG)
		std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = cpy;
}

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & assign )
{
	if (MSG)
		std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &assign)
		this->_grade = assign.getGrade();
	return *this;
}

std::string const&	Bureaucrat::getName( void ) const
{
	return ( this->_name );
}

unsigned int const&	Bureaucrat::getGrade( void ) const
{
	return ( this->_grade );
}

void	Bureaucrat::signForm( AForm &form )
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << this->getName() << " signed " << form.getName() << std::endl;
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << this->getName() << " executed " << form.getName() << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return ("Grade's too high.");
}

const char *Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return ("Grade's too low.");
}

void	Bureaucrat::incrementGrade( void )
{
	try
	{
		if (this->_grade == 1)
			throw Bureaucrat::GradeTooHighException();
		this->_grade--;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << " Can't increment grade." << std::endl;
	}
}

void	Bureaucrat::decrementGrade(void)
{
	try
	{
		if (this->_grade == 150)
			throw Bureaucrat::GradeTooLowException();
		this->_grade++;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << " Can't decrement grade." << std::endl;
	}
}

std::ostream &	operator<<( std::ostream & o, Bureaucrat const &i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << "." <<std::endl;
	return (o);
}
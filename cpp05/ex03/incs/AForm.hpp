/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:16 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/20 16:06:37 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <fstream>

class Bureaucrat;

class	AForm
{
	private:
		std::string const	_name;
		std::string const	_target;
		bool				_signed;
		unsigned int const	_grade_to_sign;
		unsigned int const	_grade_to_exec;
	
	public:
		AForm(void);
		AForm(std::string const & name, std::string const & target, unsigned int grade_to_sign, unsigned int _grade_to_exec);
		AForm(AForm const & cpy);
		virtual ~AForm(void);

		AForm &	operator=(AForm const & assign);

		std::string	const	&getName(void) const;
		std::string	const	&getTarget(void) const;
		unsigned int const	&getGradeToSign(void) const;
		unsigned int const	&getGradeToExec(void) const;
		bool const			&getSigned(void) const;

		void	beSigned(Bureaucrat const & bc);
		void	execute(Bureaucrat const & executor) const;
		virtual void	do_exec(void) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class FormAlreadySigned : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class FormNotSigned : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &	operator<<(std::ostream & o, AForm const &i);

#endif
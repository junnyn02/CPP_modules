/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:16 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/05 18:29:34 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class	AForm
{
	private:
		std::string const	_name;
		bool				_signed;
		unsigned int const	_grade_to_sign;
		unsigned int const	_grade_to_exec;
	
	public:
		AForm( void );
		AForm( std::string const & name, unsigned int grade_to_sign, unsigned int _grade_to_exec );
		AForm( std::string const & name );
		AForm( AForm const & cpy );
		virtual ~AForm( void );

		AForm &	operator=( AForm const & assign );

		std::string	const	&getName( void ) const;
		unsigned int const	&getGradeToSign( void ) const;
		unsigned int const	&getGradeToExec( void ) const;
		bool const			&getSigned( void ) const;

		void	beSigned( Bureaucrat const & bc );
		virtual void	execute( Bureaucrat const & executor ) const;
		
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

std::ostream &	operator<<( std::ostream & o, AForm const &i );

#endif
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

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class	Form
{
	private:
		std::string const	_name;
		bool				_signed;
		unsigned int const	_grade_to_sign;
		unsigned int const	_grade_to_exec;
	
	public:
		Form( void );
		Form( std::string const & name, unsigned int grade_to_sign, unsigned int _grade_to_exec );
		Form( Form const & cpy );
		~Form( void );

		Form &	operator=( Form const & assign );

		std::string	const	&getName( void ) const;
		unsigned int const	&getGradeToSign( void ) const;
		unsigned int const	&getGradeToExec( void ) const;
		bool const			&getSigned( void ) const;

		bool	beSigned( Bureaucrat const & bc );
		
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
};

std::ostream &	operator<<( std::ostream & o, Form const &i );

#endif
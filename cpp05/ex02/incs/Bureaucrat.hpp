/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:16 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/05 17:55:08 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include "AForm.hpp"

# ifndef MSG
#	define MSG 1
# endif

class AForm;

class	Bureaucrat
{
	private:
		std::string const	_name;
		unsigned int		_grade;
	
	public:
		Bureaucrat( void );
		Bureaucrat( std::string const & name, unsigned int grade );
		Bureaucrat( Bureaucrat const & cpy );
		~Bureaucrat( void );

		Bureaucrat &	operator=( Bureaucrat const & assign );

		std::string	const	&getName( void ) const;
		unsigned int const	&getGrade( void ) const;
		void				incrementGrade( void );
		void				decrementGrade( void );
		void				signForm( AForm & form );
		
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

std::ostream &	operator<<( std::ostream & o, Bureaucrat const &i );

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:16 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/20 17:03:44 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class	Intern
{
	public:
		Intern(void);
		Intern(Intern const & cpy);
		~Intern(void);

		Intern &	operator=(Intern const & assign);

		AForm *	makeForm(std::string const & name, std::string const & target);
		
		AForm	* returnShrubbery(std::string const & target);
		AForm	* returnRobot(std::string const & target);
		AForm	* returnPresident(std::string const & target);
		
		class NameNotFound : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
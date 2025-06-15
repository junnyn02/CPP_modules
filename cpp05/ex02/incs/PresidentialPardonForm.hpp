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

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{	
	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string const &target );
		PresidentialPardonForm( PresidentialPardonForm const & cpy );
		virtual ~PresidentialPardonForm( void );

		virtual void do_exec(void) const;

		PresidentialPardonForm &	operator=( PresidentialPardonForm const & assign );

};

#endif
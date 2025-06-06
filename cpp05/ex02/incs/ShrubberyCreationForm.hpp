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

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class	ShrubberyCreationForm : public AForm
{	
	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string const &name );
		ShrubberyCreationForm( ShrubberyCreationForm const & cpy );
		virtual ~ShrubberyCreationForm( void );

		ShrubberyCreationForm &	operator=( ShrubberyCreationForm const & assign );

};

#endif
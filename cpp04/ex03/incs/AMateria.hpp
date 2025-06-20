/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:16 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/19 14:08:26 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

# ifndef MSG
#	define MSG 1
#endif

class ICharacter;

class	AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const & cpy);
		virtual ~AMateria(void);

		AMateria &	operator=(AMateria const & assign);

		std::string const		&getType(void) const;

		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter &target);
};

#endif
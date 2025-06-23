/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:16 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/23 11:38:05 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class	WrongAnimal
{	
	protected:
		std::string	_type;

	public:
		WrongAnimal(void);
		WrongAnimal(std::string const & type);
		WrongAnimal(WrongAnimal const & cpy);
		virtual ~WrongAnimal(void);

		WrongAnimal &	operator=(WrongAnimal const & assign);

		std::string		getType(void) const;
		void	makeSound(void) const;
};

#endif
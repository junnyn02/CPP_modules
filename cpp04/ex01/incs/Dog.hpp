/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:16 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/17 18:44:30 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal
{
	private:
		Brain*	_brain;

	public:
		Dog(void);
		Dog(Dog const & cpy);
		virtual ~Dog(void);

		Dog &	operator=(Dog const & assign);

		virtual void	makeSound(void) const;
		void			setIdea(int index, std::string idea);
		void			getIdea(int index) const;
};

#endif
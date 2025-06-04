/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:16 by junguyen          #+#    #+#             */
/*   Updated: 2025/05/22 17:36:57 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public Animal
{
	private:
		Brain*	_brain;
	public:
		Cat( void );
		Cat( Cat const & cpy );
		virtual ~Cat( void );

		Cat &	operator=( Cat const & assign );

		virtual void	makeSound( void ) const;
		void			setIdea( int index, std::string idea );
		void			getIdea( int index ) const;
};

#endif
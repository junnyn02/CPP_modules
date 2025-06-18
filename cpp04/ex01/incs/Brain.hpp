/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:16 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/17 17:49:57 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class	Brain
{	
	private:
		std::string	_ideas[100];

	public:
		Brain(void );
		Brain(Brain const & cpy);
		~Brain(void);

		Brain &	operator=(Brain const & assign);
		void	setIdea(int index, std::string idea);
		void	getIdea(int index) const;
};

#endif
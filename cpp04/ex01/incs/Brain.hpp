/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:16 by junguyen          #+#    #+#             */
/*   Updated: 2025/05/22 17:09:26 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class	Brain{
	
	protected:
		std::string	_ideas[100];

	public:
		Brain( void );
		Brain( Brain const & cpy );
		virtual ~Brain( void );

		Brain &	operator=( Brain const & assign );
		void	setIdea( int index, std::string idea );
		void	getIdea( int index ) const;
};

#endif
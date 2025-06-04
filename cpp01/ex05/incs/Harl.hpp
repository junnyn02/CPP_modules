/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:16 by junguyen          #+#    #+#             */
/*   Updated: 2025/05/15 12:36:39 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl {
	
	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
	
	public:
		Harl( void );
		~Harl( void );
		void	complain( std::string level );
};

#endif
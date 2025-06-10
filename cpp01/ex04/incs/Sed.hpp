/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:16 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/10 14:41:49 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>
# include <string>

class Sed
{
	private:
		std::ifstream	_ifs;
		std::ofstream	_ofs;
		std::string		_line;
		std::string		_new_line;
		std::string		_old_str;
		std::string		_word;
		std::string		_new_str;

	public:
		Sed( char **av, const char *name );
		~Sed( void );
		int		check_ifs_open( void );
		int		has_find( void );
		void	replace_word( void );
		void	copy_line( void );
		void	close_iofs( void );
};

#endif
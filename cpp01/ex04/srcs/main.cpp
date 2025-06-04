/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:49:45 by junguyen          #+#    #+#             */
/*   Updated: 2025/05/14 14:30:11 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int	test_ifs( char *av )
{
	std::ifstream	infile(av);

	if (!infile.is_open())
	{
		std::cout << "Can't open file" << std::endl;
		return (1);
	}
	infile.close();
	return (0);
}

int	main( int ac, char **av )
{
	std::string		new_filename = av[1];
	const	char	*name_ofs = NULL;

	if (ac != 4)
	{
		std::cout << "Error: Wrong number of parameters" << std::endl;
		return (0);
	}
	if (test_ifs(av[1]))
		return (0);
	new_filename.append(".replace");
	name_ofs = new_filename.c_str();
	Sed	mySed( av, name_ofs );
	if (mySed.check_ifs_open() == 1)
		return (0);
	if (mySed.has_find() == 0)
		mySed.replace_word();
	mySed.copy_line();
	mySed.close_iofs();
	return (0);
}

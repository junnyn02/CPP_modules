/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:49:45 by junguyen          #+#    #+#             */
/*   Updated: 2025/05/14 16:32:16 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main( int ac, char **av )
{
	Harl	Harl;
	
	if (ac !=  2)
	{
		std::cout << "Need one parameter" << std::endl;
		return (0);
	}
	Harl.complain(av[1]);
	return (0);
}

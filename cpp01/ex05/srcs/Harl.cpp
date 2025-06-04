/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:01 by junguyen          #+#    #+#             */
/*   Updated: 2025/05/14 15:33:35 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void )
{
}

Harl::~Harl( void )
{
}

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple";
	std::cout << "-pickle-special-ketchup burger. I really do!";
	std::cout << std::endl;
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money.";
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
	std::cout << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << " I’ve been coming for years, whereas you started working here just last month.";
	std::cout << std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}

void	Harl::complain( std::string level )
{
	std::string	param[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	void		(Harl::*fn_ptr[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	Harl		speak;

	for (int i = 0; i < 4; i++)
	{
		if (level == param[i])
		{
			(speak.*fn_ptr[i])();
			return ;
		}
	}
	std::cout << "Wrong level parameter" << std::endl;
}
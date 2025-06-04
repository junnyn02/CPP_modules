/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:42:17 by junguyen          #+#    #+#             */
/*   Updated: 2025/05/21 14:20:46 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool	check_print(const char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (!isprint(str[i]))
			return (false);
	}
	return (true);
}

void	add_prompt(PhoneBook *book)
{
	std::string prompt[5] = {"First Name", "Last Name", "Nickname", "Phone Number", "Darkest Secret"};
	std::string info[5];
	
	for (int i = 0; i < 5; i++)
	{
		while (1)
		{
			std::cout << "Enter " << prompt[i] << ": " ;
			if (!std::getline(std::cin, info[i]))
			{
				std::cout << std::endl;
				return ;
			}
			if (info[i].empty())
				std::cout << "Please enter informations" << std::endl;
			else
			{
				if (!check_print(info[i].c_str()))
					std::cout << "Unknown char enter" << std::endl;
				else
					break ;
			}
		}
	}
	book->add_contact(info);
}

int	main(void)
{
	PhoneBook	book;
	std::string	cmd;

	std::cout << "Enter a command: ADD, SEARCH or EXIT: ";
	while (std::getline(std::cin, cmd))
	{
		if (cmd.compare("ADD") == 0)
			add_prompt(&book);
		else if (cmd.compare("SEARCH") == 0)
			book.search_contact();
		else if (cmd.compare("EXIT") == 0)
			return (0);
		else
			std::cout << "Command not found" << std::endl;
		std::cout << "Enter a command: ADD, SEARCH or EXIT: ";
	}
	std::cout << std::endl;
	return (0);
}

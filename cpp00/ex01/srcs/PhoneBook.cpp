/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:48:25 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/09 13:30:23 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "Welcome in your PhoneBook" << std::endl;
	_index = 0;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "End of PhoneBook" << std::endl;
}

void	PhoneBook::add_contact(std::string info[5])
{
	if (_index >= 8)
		_contact[_index % 8].set_contact(info);
	else
	{
		_contact[_index].set_contact(info);
	}
	_index++;
	std::cout << "Contact added" << std::endl;
}

void	PhoneBook::search_contact(void) const
{
	std::string input;
	for (int i = 0; i < 8; i++)
	{
		std::cout << std::setw(10) << i + 1 << "|";
		_contact[i].search_display();
		std::cout << std::endl;
	}
	std::cout << "Enter an index to display: ";
	if (!std::getline(std::cin, input))
	{
		std::cout << std::endl;
		return ;
	}
	if (std::atoi(input.c_str()) > 0 && std::atoi(input.c_str()) < 9)
	{
		if (std::atoi(input.c_str()) > _index)
			std::cout << "Contact not created yet" << std::endl;
		else
		{
			if (_index > 8)
				_contact[(std::atoi(input.c_str()) - 1) % 8].display_info();
			else
				_contact[std::atoi(input.c_str()) - 1].display_info();
		}
	}
	else
		std::cout << "Index must be between 1 and 8" << std::endl;
}

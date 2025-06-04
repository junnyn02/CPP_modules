/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:17:06 by junguyen          #+#    #+#             */
/*   Updated: 2025/03/26 16:39:55 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void){
	return;
}

Contact::~Contact(void){
	return;
}

void	Contact::set_contact(std::string info[5]){
	this->_firstName = info[0];
	this->_lastName = info[1];
	this->_nickname = info[2];
	this->_phoneNb = info[3];
	this->_darkestSecret = info[4];
}

void	Contact::search_display(void){
	if (this->_firstName.size() > 10)
		std::cout << std::setw(10) << this->_firstName.substr(0, 9) + '.' << "|"; 
	else
		std::cout << std::setw(10) << this->_firstName << "|";
	if (this->_lastName.size() > 10)
		std::cout << std::setw(10) << this->_lastName.substr(0, 9) + '.' << "|"; 
	else
		std::cout << std::setw(10) << this->_lastName << "|";
	if (this->_nickname.size() > 10)
		std::cout << std::setw(10) << this->_nickname.substr(0, 9) + '.' << "|"; 
	else
		std::cout << std::setw(10) << this->_nickname << "|";
}

void	Contact::display_info(void){
	std::cout << "First Name: " << this->_firstName << std::endl;
	std::cout << "Last Name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone Number: " << this->_phoneNb << std::endl;
	std::cout << "Darkest Secret: " << this->_darkestSecret << std::endl;
}
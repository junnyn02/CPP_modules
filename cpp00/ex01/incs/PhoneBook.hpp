/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:44:02 by junguyen          #+#    #+#             */
/*   Updated: 2025/03/26 16:17:45 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {

	private:
		Contact	_contact[8];
		int		_index; 
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add_contact(std::string info[5]);
		void	search_contact(void);
		void	search_index(std::string index);
		int		check_index(std::string input);
};

#endif
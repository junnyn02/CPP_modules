/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:15:27 by junguyen          #+#    #+#             */
/*   Updated: 2025/03/26 16:31:13 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <iostream>
# include <cstdlib>

class Contact{

	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNb;
		std::string _darkestSecret;
	public:
		Contact(void);
		~Contact(void);
		void	set_contact(std::string info[5]);
		void	search_display(void);
		void	display_info(void);
};

#endif
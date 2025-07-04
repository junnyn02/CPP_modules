/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:05:08 by junguyen          #+#    #+#             */
/*   Updated: 2025/07/04 14:18:17 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data data;
	Data *deserialize = NULL;
	uintptr_t	raw;
	
	data._age = 26;
	data._name = "Julien";
	data._phone = "0102030405";
	std::cout << data._name << " " << data._age << " " << data._phone << std::endl;
	raw = Serializer::serialize(&data);
	deserialize = Serializer::deserialize(raw);
	std::cout << deserialize->_name << " " << deserialize->_age << " " << deserialize->_phone << std::endl;
	return 0;
}
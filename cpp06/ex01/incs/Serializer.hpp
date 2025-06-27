/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:16 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/27 16:24:27 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include "stdint.h"
# include "Data.hpp"

# ifndef MSG
#	define MSG 1
# endif

class	Serializer
{
	private:
		Serializer(void);
		Serializer(Serializer const & cpy);
		~Serializer(void);
		Serializer &	operator=(Serializer const & assign);
	
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
};

#endif
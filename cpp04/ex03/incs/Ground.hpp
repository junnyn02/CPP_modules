/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ground.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:16 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/18 17:50:39 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GROUND_HPP
# define GROUND_HPP

# include "AMateria.hpp"

class	Ground
{
	private:
		AMateria	*_drop[100];

	public:
		Ground(void);
		Ground(Ground const & cpy);
		virtual ~Ground(void);

		Ground &	operator=(Ground const & assign);

		void	add(AMateria *unequip);
};

#endif
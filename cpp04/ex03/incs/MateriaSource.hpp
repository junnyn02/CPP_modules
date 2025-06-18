/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:44:16 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/18 12:44:10 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_stock[4];

	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & cpy);
		virtual ~MateriaSource(void);

		MateriaSource &	operator=(MateriaSource const & assign);

		virtual void	learnMateria(AMateria *);
		virtual AMateria	*createMateria(std::string const & type);
};

#endif
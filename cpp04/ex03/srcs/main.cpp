/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:05:08 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/04 14:40:57 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "IMateriaSource.hpp"
// #include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();

	std::cout << std::endl << "----------------------" << std::endl << std::endl;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << std::endl << "----------------------" << std::endl << std::endl;
	ICharacter* me = new Character("me");
	AMateria* tmp;
	std::cout << std::endl << "----------------------" << std::endl << std::endl;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << std::endl << "----------------------" << std::endl << std::endl;
	ICharacter* bob = new Character("bob");
	std::cout << std::endl << "----------------------" << std::endl << std::endl;

	me->use(0, *bob);
	me->use(1, *bob);

	//more test
	std::cout << std::endl << "----------------------" << std::endl << std::endl;
	me->use(2, *bob);
	tmp = src->createMateria("fire");
	me->equip(tmp);
	me->use(2, *bob);
	std::cout << std::endl << "----------------------" << std::endl << std::endl;
	delete bob;
	delete me;
	delete src;

	return 0;
}
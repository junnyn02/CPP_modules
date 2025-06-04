/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:49:45 by junguyen          #+#    #+#             */
/*   Updated: 2025/05/27 15:18:47 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int	main( void )
{
	std::cout << "------------ SUBJECT TEST ------------" << std::endl;
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	std::cout << std::endl << "------------ ARRAY ANIMAL TEST ------------" << std::endl;
	int	size = 10;
	const AAnimal	*animal[size];

	for (int i = 0; i < size / 2; i++)
		animal[i] = new Dog();
	for (int i = size / 2; i < size; i++)
		animal[i] = new Cat();
	for (int i = 0; i < size; i++)
	{
		std::cout << animal[i]->getType() << " ";
		animal[i]->makeSound();
	}
	for (int i = 0; i < size; i++)
		delete animal[i];
	
	std::cout << std::endl << "------------ DEEP COPY ANIMAL TEST ------------" << std::endl;
	Dog *snoopy = new Dog();
	for (int i = 0; i < 10; i++)
		snoopy->setIdea(i, "I love play ");
	for (int i = 0; i < 10; i++)
		snoopy->getIdea(i);
	Dog *snoopy_cpy2 = new Dog(*snoopy);

	delete snoopy ;

	for (int i = 0; i < 10; i++)
		snoopy_cpy2->getIdea(i);

	delete snoopy_cpy2 ;
	return (0);
}

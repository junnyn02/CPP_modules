/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:49:45 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/17 15:58:39 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main( void )
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " ";
	j->makeSound();
	std::cout << i->getType() << " ";
	i->makeSound(); //will output the cat sound!
	meta->makeSound();

	const WrongAnimal* False = new WrongCat();

	std::cout << False->getType() << " ";
	False->makeSound();

	delete (meta);
	delete (j);
	delete (i);
	delete (False);

	return (0);
}

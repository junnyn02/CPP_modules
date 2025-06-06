/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:05:08 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/05 18:32:33 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	ShrubberyCreationForm a("target");
	std::cout << a;
	// Bureaucrat	Bob("Bob", 152);
	// std::cout << Bob;

	// Bureaucrat	Patrick("Patrick", 150);
	// std::cout << Patrick;
	// Patrick.decrementGrade();
	// std::cout << Patrick;

	// Bureaucrat	Boss("Boss", 2);
	// std::cout << Boss;
	// Boss.incrementGrade();
	// std::cout << Boss;
	// Boss.incrementGrade();
	// std::cout << Boss;

	// Form a("Contract", 1, 1);
	// Patrick.signForm(a);

	// Boss.signForm(a);
	// Bureaucrat	Vice("Vice Pres", 2);
	// Vice.signForm(a);

	return 0;
}
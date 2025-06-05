/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:05:08 by junguyen          #+#    #+#             */
/*   Updated: 2025/06/05 15:01:01 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat	Bob("Bob", 152);
	std::cout << Bob;

	Bureaucrat	Patrick("Patrick", 150);
	std::cout << Patrick;
	Patrick.decrementGrade();
	std::cout << Patrick;

	Bureaucrat	Boss("Boss", 2);
	std::cout << Boss;
	Boss.incrementGrade();
	std::cout << Boss;
	Boss.incrementGrade();
	std::cout << Boss;
	return 0;
}
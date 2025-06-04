/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junguyen <junguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:49:45 by junguyen          #+#    #+#             */
/*   Updated: 2025/05/21 17:30:19 by junguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int	main( void )
{
	Point a(1.5f, 0.5f);
	Point b(2.3f, 10.6f);
	Point c(10.4f, 0.7f);
	Point point(5.2f, 2.4f);

	Point d(1.5f, 0.5f);
	Point e(2.3f, 10.6f);
	Point f(10.4f, 0.7f);
	Point point2(0.2f, 12.8f);

	Point g = a;

	std::cout << g << std::endl;

	if (bsp(a, b, c, point))
		std::cout << "The point is inside the triangle" << std::endl;
	else
		std::cout << "The point isn't inside the triangle" << std::endl;
	if (bsp(d, e, f, point2))
		std::cout << "The point is inside the triangle" << std::endl;
	else
		std::cout << "The point isn't inside the triangle" << std::endl;
	return (0);
}

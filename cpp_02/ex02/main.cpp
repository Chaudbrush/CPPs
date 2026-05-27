/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 19:15:50 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/16 12:33:28 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << "Initial tests:" << std::endl;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	Fixed c(3.7869f);
	Fixed d(3.7869f);
	Fixed e(3.7831f);
	Fixed f(3.7834f);

	std::cout << "Comparison tests:" << std::endl;

	if (c == d)
		std::cout << "c and d are equal" << std::endl;
	else
		std::cout << "c and d are different" << std::endl;

	if (e == d)
		std::cout << "e and d are equal" << std::endl;
	else
		std::cout << "e and d are different" << std::endl;

	if (f > e)
		std::cout << "f is greater than e" << std::endl;
	else
		std::cout << "f is NOT greater than e" << std::endl;
		
	Fixed sum1(35.0625f);
	Fixed sum2(42.125f);
	std::cout << "sum1 + sum2 is: " << sum1 + sum2 << std::endl;
	std::cout << "sum1 + sum2 + 0.0625f is: " << sum1 + sum2 + 0.0625f << std::endl;
	std::cout << "sum1 + sum2 + 0.0625f + 0.0625f is: " << sum1 + sum2 + 0.0625f + 0.0625f << std::endl;
	
	Fixed mult1(35.25f);
	Fixed mult2(1.75f);
	std::cout << "mult1 + mult2 is: " << mult1 * mult2 << std::endl;

	Fixed div1(12.25f);
	Fixed div2(7.125f);
	std::cout << "div1 + div2 is: " << div1 / div2 << std::endl;

	Fixed const max1(12.25f);
	Fixed const max2(7.125f);
	std::cout << "max1 is: " << max1 << ", max2 is: " << max2 << ". The grater is: " << max1.max(max1, max2) << std::endl;

	Fixed min1(0.0625f);
	Fixed min2(-0.125f);
	std::cout << "min1 is: " << min1 << ", min2 is: " << min2 << ". The smallest is: " << min1.min(min1, min2) << std::endl;

	return 0;
}
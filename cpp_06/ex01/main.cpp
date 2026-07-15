/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 16:57:41 by vloureir          #+#    #+#             */
/*   Updated: 2026/04/09 12:14:32 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data x;
	Data *y = NULL;
	uintptr_t raw = 0;

	x.value = 25;
	x.str = "hello world";
	x.c = 'z';

	std::cout << "--- Before ---\n";
	std::cout << x.value << std::endl;
	std::cout << x.str << std::endl;
	std::cout << x.c << std::endl;

	raw = Serializer::serialize(&x);
	y = Serializer::deserialize(raw);

	std::cout << "\n--- After ---\n";
	std::cout << y->value << std::endl;
	std::cout << y->str << std::endl;
	std::cout << y->c << std::endl;
}
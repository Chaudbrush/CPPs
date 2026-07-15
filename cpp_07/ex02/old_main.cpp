/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 09:54:13 by vloureir          #+#    #+#             */
/*   Updated: 2026/04/05 11:51:09 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	int size = 4;

	Array<int> data_i(size);
	for (int i = 0; i < size; i++)
		data_i[i] = i * 3;

	data_i.print();
	std::cout << data_i.size() << std::endl;

	Array<float> data_f(size);
	for (int i = 0; i < size; i++)
		data_f[i] = i / 3.0f;

	data_f.print();
	std::cout << data_f.size() << std::endl;

	Array<char *> data_str(size);
	for (int i = 0; i < size; i++)
		data_str[i] = "hi";

	data_str.print();
	std::cout << data_str.size() << std::endl;

	// Array<std::string> data_str(size);
	// for (int i = 0; i < size; i++)
	// 	data_str[i] = std::to_string(i + 10);

	// data_str.print();
	// std::cout << data_str.size() << std::endl;
}
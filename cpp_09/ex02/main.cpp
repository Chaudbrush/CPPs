/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 10:06:47 by vloureir          #+#    #+#             */
/*   Updated: 2026/07/14 12:28:15 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe data;
	struct timeval start;
	struct timeval end;

	if (data.valid_input(ac, av) == -1)
		return (1);

	std::cout << "Before:	";
	data.printClean(data.getVector(), 0);

	// Vec Time
	gettimeofday(&start, 0);
	std::vector<t_pairs *> resultVec = data.vectorRecursion(data.getVector());
	gettimeofday(&end, 0);
	double vec_time = (end.tv_sec - start.tv_sec) * 1e3 + (end.tv_usec - start.tv_usec) * 1e-3;

	// Dq Time
	gettimeofday(&start, 0);
	std::deque<t_pairs *> resultDq = data.dequeRecursion(data.getDeque());
	gettimeofday(&end, 0);
	double dq_time = (end.tv_sec - start.tv_sec) * 1e3 + (end.tv_usec - start.tv_usec) * 1e-3;

	std::cout << "After:	";
	data.printClean(resultVec, 1);

	int numbers = resultDq.size();	
	std::cout << "Time to process a range of " << numbers << " elements with std::vector: " << vec_time << " ms" << std::endl;
	std::cout << "Time to process a range of " << numbers << " elements with std::deque: " << dq_time << " ms" << std::endl;

	std::cout << "Comparisons for " << numbers  << " numbers: " << data.getComparisons() << std::endl;
	return (0);
}

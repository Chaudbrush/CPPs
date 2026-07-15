/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 09:16:54 by vloureir          #+#    #+#             */
/*   Updated: 2026/07/14 17:25:19 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Sorting
std::vector<t_pairs *> PmergeMe::vectorRecursion(std::vector<t_pairs *> &input)
{
	std::vector<t_pairs *> pairs;
	t_pairs	*odd = NULL;
	int odd_flag = 0;
	int n = input.size();

	if (input.size() == 1)
	{
//		std::cout << std::endl;
		std::vector<t_pairs *> max;
		max.push_back(input[0]);
		return (max);
	}
	if (n % 2 != 0)
	{
		odd_flag = 1;
		odd = input[n - 1];
	}

	// std::cout << "IN:  ";
	// printSteps(input, odd, 0);

	for (int i = 0; i < n - 1; i += 2)
	{
//		comparisons++;
		if (input[i]->value > input[i + 1]->value)
		{
			t_pairs *tmp = input[i];
			input[i] = input[i + 1];
			input[i + 1] = tmp;
		}
		input[i + 1]->losers.push_back(input[i]);
		pairs.push_back(input[i + 1]);
	}
	
	std::vector<t_pairs *> result = vectorRecursion(pairs);
	// std::cout << "OUT: ";
	// printSteps(result, odd, 0);

	int pending = result.size() + odd_flag; // pend size will be all the winner chain + the odd element if it exists
	// Insert the loser of the smallest element
	t_pairs *tmp = result[0]->losers[result[0]->losers.size() - 1];
	result[0]->losers.pop_back();
	result.insert(result.begin(), tmp);
	pending--; // loser of the smallest element is added
	
	std::vector<t_pairs *> insert_ref(result);
	// std::cout << "PND: ";
	// printSteps(insert_ref, odd, odd_flag);

	result = jacobInsertionVec(result, insert_ref, odd, odd_flag, pending);
	// std::cout << "JCB: ";
	// printSteps(result, odd, 0);
	// std::cout << std::endl;

	return (result);
}

std::deque<t_pairs *> PmergeMe::dequeRecursion(std::deque<t_pairs *> &input)
{
	std::deque<t_pairs *> pairs;
	t_pairs	*odd = NULL;
	int odd_flag = 0;
	int n = input.size();

	if (input.size() == 1)
	{
//		std::cout << std::endl;
		std::deque<t_pairs *> max;
		max.push_back(input[0]);
		return (max);
	}
	if (n % 2 != 0)
	{
		odd_flag = 1;
		odd = input[n - 1];
	}

	// std::cout << "IN:  ";
	// printSteps(input, odd, 0);

	for (int i = 0; i < n - 1; i += 2)
	{
		comparisons++;
		if (input[i]->value > input[i + 1]->value)
		{
			t_pairs *tmp = input[i];
			input[i] = input[i + 1];
			input[i + 1] = tmp;
		}
		input[i + 1]->losers.push_back(input[i]);
		pairs.push_back(input[i + 1]);
	}

	std::deque<t_pairs *> result = dequeRecursion(pairs);
	// std::cout << "OUT: ";
	// printSteps(result, odd, 0);

	int pending = result.size() + odd_flag; // pend size will be all the winner chain + the odd element if it exists
	// Insert the loser of the smallest element
	t_pairs *tmp = result[0]->losers[result[0]->losers.size() - 1];
	result[0]->losers.pop_back();
	result.insert(result.begin(), tmp);
	pending--; // loser of the smallest element is added

	std::deque<t_pairs *> insert_ref(result);
	// std::cout << "PND: ";
	// printSteps(insert_ref, odd, odd_flag);

	result = jacobInsertionDq(result, insert_ref, odd, odd_flag, pending);
	// std::cout << "JCB: ";
	// printSteps(result, odd, 0);
	// std::cout << std::endl;
	
	return (result);
}

// Jacobsthal
// 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525

std::vector<t_pairs *> PmergeMe::jacobInsertionVec(std::vector<t_pairs *> result, std::vector<t_pairs *> insert_ref, t_pairs *odd, int odd_flag, int pending)
{
	int old_jacob = 1;
	int jacob = getJacob(RESET);

	int end_index;

	while (pending > 0)
	{
		jacob = getJacob(NO_RESET);
		if (jacob < static_cast<int>(insert_ref.size()))
		{
			for (int i = jacob; i > old_jacob; i--, pending--)
			{
				end_index = getEndVec(result, insert_ref[i]);
				binaryInsertionVec(result, insert_ref[i]->losers[insert_ref[i]->losers.size() - 1], 0, end_index);
				insert_ref[i]->losers.pop_back();
			}
			old_jacob = jacob;
		}
		else
		{
			if (odd_flag)
			{
				end_index = result.size() - 1;
				binaryInsertionVec(result, odd, 0, end_index);
				odd_flag = 0;
				pending--;
			}
			for (int i = insert_ref.size() - 1; pending > 0; i--, pending--)
			{
				end_index = getEndVec(result, insert_ref[i]);
				binaryInsertionVec(result, insert_ref[i]->losers[insert_ref[i]->losers.size() - 1], 0, end_index);
				insert_ref[i]->losers.pop_back();
			}
		}
	}
	return (result);
}

std::deque<t_pairs *> PmergeMe::jacobInsertionDq(std::deque<t_pairs *> result, std::deque<t_pairs *> insert_ref, t_pairs *odd, int odd_flag, int pending)
{
	int old_jacob = 1;
	int jacob = getJacob(RESET);

	int end_index;

	while (pending > 0)
	{
		jacob = getJacob(NO_RESET);
		if (jacob < static_cast<int>(insert_ref.size()))
		{
			for (int i = jacob; i > old_jacob; i--, pending--)
			{
				end_index = getEndDq(result, insert_ref[i]);
				binaryInsertionDq(result, insert_ref[i]->losers[insert_ref[i]->losers.size() - 1], 0, end_index);
				insert_ref[i]->losers.pop_back();
			}
			old_jacob = jacob;
		}
		else
		{
			if (odd_flag)
			{
				end_index = result.size() - 1;
				binaryInsertionDq(result, odd, 0, end_index);
				odd_flag = 0;
				pending--;
			}
			for (int i = insert_ref.size() - 1; pending > 0; i--, pending--)
			{
				end_index = getEndDq(result, insert_ref[i]);
				binaryInsertionDq(result, insert_ref[i]->losers[insert_ref[i]->losers.size() - 1], 0, end_index);
				insert_ref[i]->losers.pop_back();
			}
		}
	}
	return (result);
}

void PmergeMe::binaryInsertionVec(std::vector<t_pairs *> &data, t_pairs *loser, int start, int end)
{
	int mid;
	while (start <= end)
	{
//		comparisons++;
		mid = (end + start) / 2;
		if (loser->value < data[mid]->value)
			end = mid - 1;
		else
			start = mid + 1;
	}
	data.insert(data.begin() + start, loser);
}

void PmergeMe::binaryInsertionDq(std::deque<t_pairs *> &data, t_pairs *loser, int start, int end)
{
	int mid;
	while (start <= end)
	{
		comparisons++;
		mid = (end + start) / 2;
		if (loser->value < data[mid]->value)
			end = mid - 1;
		else
			start = mid + 1;
	}
	data.insert(data.begin() + start, loser);
}


// Parsing
int PmergeMe::valid_input(int ac, char **av)
{
	t_pairs pair;
	raw.reserve(ac - 1);
	vec.reserve(ac - 1);
	if (ac == 1)
	{
		std::cerr << "Error: Missing arguments\n";
		return (-1);
	}
	for (int i = 0; i < ac - 1; i++)
	{
		int num = PmergeMe::valid_numbers(av[i + 1], raw);
		if (num == -1)
			return (-1);

		pair.value = num;
		raw.push_back(pair);
		vec.push_back(&raw[i]);
		dq.push_back(&raw[i]);
	}
	return (0);
}

int PmergeMe::valid_numbers(char *input, std::vector<t_pairs>& vec)
{
	long result;
	char *end = NULL;

	result = strtol(input, &end, 10);
	if (!input[0] || result < 0 || result > INT_MAX || *end)
	{
		std::cerr << "Error: Invalid numeric argument\n";
		return (-1);
	}
	for (std::vector<t_pairs>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (it->value == result)
		{
			std::cerr << "Error: Duplicated argument\n";
			return (-1);
		}
	}
	return (result);
}


// Getters
std::vector<t_pairs *>& PmergeMe::getVector(void)
{ 
	return (vec); 
}

std::deque<t_pairs *>& PmergeMe::getDeque(void) 
{ 
	return (dq); 
}

int PmergeMe::getComparisons(void) const 
{ 
	return (comparisons); 
}

int PmergeMe::getJacob(int flag)
{
	static int x = 3;
	if (flag)
		x = 2;
	int res = (pow(2, x) - pow(-1, x)) / 3;
	x++;
	return (res);
}

int PmergeMe::getEndVec(std::vector<t_pairs *> &input, t_pairs *target)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		if (input[i] == target)
			return (i - 1);
	}
	return (0);
}

int PmergeMe::getEndDq(std::deque<t_pairs *> &input, t_pairs *target)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		if (input[i] == target)
			return (i - 1);
	}
	return (0);
}


// Orthodox Cannonical Form
PmergeMe::PmergeMe() : comparisons(0)
{
	
}

PmergeMe::PmergeMe(const PmergeMe& rhs)
{
	*this = rhs;
}

PmergeMe::~PmergeMe()
{
	
}

PmergeMe &PmergeMe::operator=(const PmergeMe& rhs)
{
	if (this != &rhs)
	{
		raw = rhs.raw;
		vec = rhs.vec;
		dq = rhs.dq;
		comparisons = rhs.comparisons;
	}
	return (*this);
}

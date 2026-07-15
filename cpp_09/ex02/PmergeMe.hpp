/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 10:02:19 by vloureir          #+#    #+#             */
/*   Updated: 2026/07/14 17:24:49 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <climits>
# include <cmath>
# include <deque>
# include <iostream>
# include <sys/time.h>
# include <vector>

# define RESET 1
# define NO_RESET 0

typedef struct s_pairs
{
	int		value;
	std::vector<struct s_pairs *> losers;
}	t_pairs;

class PmergeMe
{
	typedef std::deque<t_pairs *> t_dq;
	typedef std::vector<t_pairs *> t_vec;
public:
	// Parsing
	int		valid_input(int ac, char **av);
	int		valid_numbers(char *input, std::vector<t_pairs>& vec);

	// Sorting
	t_vec	vectorRecursion(t_vec &input);
	t_dq	dequeRecursion(t_dq &input);
	void	binaryInsertionDq(t_dq &data, t_pairs *loser, int start, int end);
	void	binaryInsertionVec(t_vec &data, t_pairs *loser, int start, int end);
	t_dq	jacobInsertionDq(t_dq result, t_dq pend, t_pairs *odd, int odd_flag, int pending);
	t_vec	jacobInsertionVec(t_vec result, t_vec pend, t_pairs *odd, int odd_flag, int pending);

	// Getters
	t_dq&	getDeque(void);
	t_vec&	getVector(void);
	int		getJacob(int flag);
	int		getComparisons(void) const;
	int		getEndDq(t_dq &input, t_pairs *target);
	int		getEndVec(t_vec &input, t_pairs *target);

	PmergeMe();
	PmergeMe(const PmergeMe& rhs);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe& rhs);

	// Print Utils
	template <typename T>
	void printClean(T data, int flag)
	{
		int n = data.size();
		for (int i = 0; i < n; i++)
		{
			if (flag && i < n - 1 && data[i]->value > data[i + 1]->value)
			{
				std::cout << "\e[38;5;160m[" << data[i]->value << " " << data[i + 1]->value << "]\e[0;0;0m ";
				i++;
			}
			else
				std::cout << data[i]->value << " ";
		}
		std::cout << std::endl;	
	}

	template <typename T, typename U>
	void printSteps(T &vec, U& odd, int flag)
	{	
		int n = vec.size();
		for (int i = 0; i < n; i++)
		{
			std::cout << "\e[38;5;75m[" << vec[i]->value << "]\e[0;0;0m ";
			for (size_t j = 0; j < vec[i]->losers.size(); j++)
				std::cout << "-> " << "(" << vec[i]->losers[j]->value << ") ";
		}
		if (flag)
		{
			std::cout << "\e[38;5;41m[" << odd->value << "]\e[0;0;0m ";
			for (size_t j = 0; j < odd->losers.size(); j++)
				std::cout << "-> " << "(" << odd->losers[j]->value << ") ";
		}
		std::cout << std::endl;
	}
private:
	std::vector<t_pairs>	raw;
	std::vector<t_pairs *>	vec;
	std::deque<t_pairs *>	dq;
	int						comparisons;
};
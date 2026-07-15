/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:34:39 by vloureir          #+#    #+#             */
/*   Updated: 2026/07/01 07:58:47 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <algorithm>
# include <cstdlib>
# include <cstring>
# include <iostream>
# include <stdexcept>
# include <vector>

typedef struct std::pair<std::vector<int>::iterator, std::vector<int>::iterator> t_pair_iterator;

class Span
{
public:
	// Utils
	void print(void) const;
	void printAddr(void) const;
	size_t	get_size(void) const;

	void addNumber(int num);

	template <typename InputIterator>
	void addRange(InputIterator begin, InputIterator end);

	template <typename InputIterator>
	void addRange(std::vector<int>::const_iterator pos, InputIterator begin, InputIterator end);

	int shortestSpan(void);
	int longestSpan(void);

	std::vector<int>::const_iterator getBegin() const;
	std::vector<int>::const_iterator getEnd() const;

	Span();
	Span(unsigned int num);
	Span(const Span& other);
	~Span();

	Span &operator=(const Span& other);

private:
	unsigned int max;
	unsigned int index;
	std::vector<int> data;
};

# include "Span.tpp"
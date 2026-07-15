/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 22:29:04 by vloureir          #+#    #+#             */
/*   Updated: 2026/07/01 07:58:10 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

template <typename InputIterator>
void Span::addRange(InputIterator begin, InputIterator end)
{
	try
	{
		if (begin > end)
			throw(std::out_of_range("-error: invalid position iterator"));
		for (InputIterator it = begin; it != end; it++)
		{
			if (index >= max)
				throw(std::out_of_range("-error: not enough capacity"));
			data[index] = *it;
			index++;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

// vec.being   <=   pos   <=   vec.end()
template <typename InputIterator>
void Span::addRange(std::vector<int>::const_iterator pos, InputIterator begin, InputIterator end)
{
	std::cout << "INITIAL INDEX: " << pos - this->getBegin()<< std::endl;
	try
	{
		if (this->data.begin() > pos || this->data.end() < pos || begin > end)
			throw(std::out_of_range("-error: invalid position iterator"));
			
		unsigned int start = pos - this->getBegin();
		if (start > index)
			start = index;
		int amount = end - begin;

		if (index + amount > max)
				throw(std::out_of_range("-error: not enough capacity"));
		for (unsigned int i = index; i >= start; i--)
			data[i + amount] = data[i];
		for (InputIterator it = begin; it != end; it++, index++, start++)
			data[start] = *it;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

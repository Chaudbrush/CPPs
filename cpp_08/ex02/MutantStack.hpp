/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 10:46:05 by vloureir          #+#    #+#             */
/*   Updated: 2026/06/25 12:23:41 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <deque>
# include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	typedef typename std::stack<T, Container>::container_type::iterator iterator;
	typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T, Container>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T, Container>::container_type::const_reverse_iterator const_reverse_iterator;

	MutantStack();
	MutantStack(const MutantStack& other);
	MutantStack& operator=(const MutantStack& other);
	~MutantStack();

	iterator begin(void);
	iterator end(void);

	const_iterator begin(void) const;
	const_iterator end(void) const;

	reverse_iterator rbegin(void);
	reverse_iterator rend(void);

	const_reverse_iterator rbegin(void) const;
	const_reverse_iterator rend(void) const;

private:
};

#include "MutantStack.tpp"
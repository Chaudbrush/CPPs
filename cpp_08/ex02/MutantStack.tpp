/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 10:59:54 by vloureir          #+#    #+#             */
/*   Updated: 2026/06/25 12:23:15 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// Forward Iterators
template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin(void)
{ 
	return (this->c.begin()); 
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end(void)
{ 
	return (this->c.end()); 
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin(void) const
{ 
	return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end(void) const
{ 
	return (this->c.end());
}


// Reverse Iterators
template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin(void)
{ 
	return (this->c.rbegin()); 
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend(void)
{ 
	return (this->c.rend()); 
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rbegin(void) const
{ 
	return (this->c.rbegin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rend(void) const
{ 
	return (this->c.rend());
}


// Orthodox Cannonical Form
template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>()
{

}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other) : std::stack<T, Container>(other)
{

}

template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& other)
{
	if (this != &other)
	{
		this->c = other.c;
	}
	return (*this);
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{

}
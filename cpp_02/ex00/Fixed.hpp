/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:39:36 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/16 11:28:31 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
public:
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	Fixed();
	Fixed(const Fixed& other);
	~Fixed();

	Fixed &operator=(const Fixed& other);

private:
	int	fixed;
	static const int fractional;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:39:36 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/16 11:28:44 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& other);
		~Fixed();

		Fixed &operator=(const Fixed& other);
		
		Fixed operator+(const Fixed& other);
		Fixed operator-(const Fixed& other);
		Fixed operator*(const Fixed& other);
		Fixed operator/(const Fixed& other);

		bool operator>(const Fixed& other);
		bool operator<(const Fixed& other);
		bool operator>=(const Fixed& other);
		bool operator<=(const Fixed& other);
		bool operator==(const Fixed& other);
		bool operator!=(const Fixed& other);

		Fixed operator++(void);
		Fixed operator++(int); // Dummy parameter, postfix version
		Fixed operator--(void);
		Fixed operator--(int); // Dummy parameter, postfix version

		static Fixed &min(Fixed& f1, Fixed& f2);
		static Fixed &max(Fixed& f1, Fixed& f2);
		const static Fixed &min(const Fixed& f1, const Fixed& f2);
		static const Fixed &max(const Fixed& f1, const Fixed& f2);
		
	private:
		int	fixed;
		static const int fractional;
};

std::ostream &operator<<(std::ostream& out, const Fixed& other);

#endif
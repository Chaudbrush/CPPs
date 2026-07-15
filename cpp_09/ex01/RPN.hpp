/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 10:31:20 by vloureir          #+#    #+#             */
/*   Updated: 2026/07/13 18:46:22 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <list>

class RPN
{
public:
	std::string evalLine(std::string line);

	RPN();
	RPN(const RPN& rhs);
	~RPN();

	RPN& operator=(const RPN& rhs);

private:
	std::list<float> nums;
};

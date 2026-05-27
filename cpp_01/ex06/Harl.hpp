/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 20:24:54 by vloureir          #+#    #+#             */
/*   Updated: 2026/03/13 11:09:02 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

# define DEBUG_MSG "I love drawing more cards than anybody else. I really do!"
# define INFO_MSG "I cannot believe adding two extra lands on my deck would flood me so many games. If I haven't, I'd be having perfect games!"
# define WARNING_MSG "I think I deserve some free turns without being attacked, I haven't won any games today. If I had, you'd be free to attack me!"
# define ERROR_MSG "This is unnaceptable! I want to win some games today!"
# define DEFAULT_MSG "[Feeling sad because there is no one to play MtG today...]"

enum{
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

class Harl
{
public:
	void	complain(std::string level);

private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:19:59 by yoel              #+#    #+#             */
/*   Updated: 2023/04/13 20:08:52 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl(void)
{}

Harl::~Harl(void)
{}

void	Harl::complain(std::string level)
{
	int	i = 0;
	std::string levels[4] \
	= {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*fPointers[4])(void) \
	= {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	// for (int i = 0; levels[i] != level && i < 4; i++);
	while (i < 4 && levels[i] != level)
		i++;
	i = i % 4;
	switch (i)
	{
		case 0:
			(this->*fPointers[i++])();
		case 1:
			(this->*fPointers[i++])();
		case 2:
			(this->*fPointers[i++])();
		case 3:
			(this->*fPointers[i])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}

void	Harl::debug(void)
{
	std::cout << DEBUG;
}

void	Harl::info(void)
{
	std::cout << INFO;
}

void	Harl::warning(void)
{
	std::cout << WARNING;
}

void	Harl::error(void)
{
	std::cout << ERROR;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <yoel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:19:59 by yoel              #+#    #+#             */
/*   Updated: 2023/04/13 00:11:34 by yoel             ###   ########.fr       */
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
	std::string levels[4] \
	= {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*fPointers[4])(void) \
	= {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*fPointers[i])();
			break;
		}
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

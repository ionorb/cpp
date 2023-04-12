/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <yoel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:03:59 by yoel              #+#    #+#             */
/*   Updated: 2023/04/12 20:58:08 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string new_name, Weapon& new_weapon)
{
	weapon = &new_weapon;
	name = new_name;
	std::cout << "humanA created\n";
}

HumanA::~HumanA(void)
{
	std::cout << "humanA destroyed\n";
}

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " 
			  << weapon->getType() << std::endl;
}
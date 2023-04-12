/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <yoel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:04:05 by yoel              #+#    #+#             */
/*   Updated: 2023/04/12 20:59:55 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string new_name)
{
	name = new_name;
	std::cout << "humanB created\n";
}

HumanB::~HumanB(void)
{
	std::cout << "humanB destroyed\n";
}

void	HumanB::attack(void)
{
	std::cout << name << " attacks with their " 
			  << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& new_weapon)
{
	weapon = &new_weapon;
}

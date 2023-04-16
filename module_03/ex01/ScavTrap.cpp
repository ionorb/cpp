/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 20:46:41 by yridgway          #+#    #+#             */
/*   Updated: 2023/04/16 21:09:00 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	this->hp = 100;
	this->energy = 50;
	this->damage = 20;
	std::cout << "scav Trap Created\n";
}

ScavTrap::ScavTrap(const ScavTrap& scav) : ClapTrap(scav.name)
{
	std::cout << "scav Trap Created\n";
	*this = scav;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "scav Trap Destroyed\n";
}

ScavTrap&	ScavTrap::operator = (const ScavTrap& scav)
{
	if (&scav != this)
	{
		this->hp = scav.hp;
		this->energy = scav.energy;
		this->damage = scav.damage;
		this->name = scav.name;
	}
	return (*this);
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << name << "is in Gate keeper mode\n";
}
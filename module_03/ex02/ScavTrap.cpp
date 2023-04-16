/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 20:46:41 by yridgway          #+#    #+#             */
/*   Updated: 2023/04/16 21:23:48 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	this->hp = 100;
	this->energy = 50;
	this->damage = 20;
	std::cout << "Scav Trap " << this->name << " Created\n";
}

ScavTrap::ScavTrap(const ScavTrap& scav) : ClapTrap(scav.name)
{
	std::cout << "scav Trap Created\n";
	*this = scav;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Scav Trap " << this->name << " Destroyed\n";
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

void	ScavTrap::attack(const std::string& target)
{
	if (this->hp <= 0)
		std::cout << "[ScavTrap] " << this->name << " cannot attack while dead!\n";
	else if (this->energy <= 0)
		std::cout << this->name << " has no energy to attack!\n";
	else
	{
		std::cout << "[ScavTrap] " << this->name << " attacks " << target \
		<< ", causing " << this->damage << " points of damage!\n";
		this->energy -= 1;
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << name << " is in Gate keeper mode\n";
}
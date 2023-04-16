/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:48:05 by yridgway          #+#    #+#             */
/*   Updated: 2023/04/16 21:23:39 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hp = 10;
	this->energy = 10;
	this->damage = 0;
	std::cout << "Clap Trap " << this->name << " Created\n";
}

ClapTrap::ClapTrap(const ClapTrap& clap)
{
	std::cout << "Clap Trap Created\n";
	*this = clap;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Clap Trap " << this->name << " Destroyed\n";
}

ClapTrap&	ClapTrap::operator = (const ClapTrap& clap)
{
	if (&clap != this)
	{
		this->hp = clap.hp;
		this->energy = clap.energy;
		this->damage = clap.damage;
		this->name = clap.name;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->hp <= 0)
		std::cout << this->name << " cannot attack while dead!\n";
	else if (this->energy <= 0)
		std::cout << this->name << " has no energy to attack!\n";
	else
	{
		std::cout << this->name << " attacks " << target \
		<< ", causing " << this->damage << " points of damage!\n";
		this->energy -= 1;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hp <= 0)
		std::cout << this->name << " is already dead!\n";
	else
	{
		std::cout << this->name << " takes " << amount << " damage!\n";
		this->hp -= amount;
		if (this->hp <= 0)
			std::cout << this->name << " DIED\n";
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hp <= 0)
		std::cout << this->name << " cannot repair himself while dead!\n";
	else if (this->energy <= 0)
		std::cout << this->name << " has no energy to repair himself!\n";
	else
	{
		std::cout << this->name << " repairs himself with " << amount << " hit points\n";
		this->hp += amount;
		this->energy -= 1;
	}
}

int				ClapTrap::getHP()
{
	return (this->hp);
}

int				ClapTrap::getDamage()
{
	return (this->damage);
}

int				ClapTrap::getEnergy()
{
	return (this->energy);
}

std::string		ClapTrap::getName()
{
	return (this->name);
}

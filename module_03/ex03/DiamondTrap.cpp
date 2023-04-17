/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:26:49 by yridgway          #+#    #+#             */
/*   Updated: 2023/04/17 18:43:06 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) \
: ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->hp = FragTrap::hp;
	this->energy = ScavTrap::energy;
	this->damage = FragTrap::damage;
	std::cout << "Diamond Trap " << this->name << " Created\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& dia) \
: ClapTrap(dia.name + "_clap_name"), FragTrap(dia.name), ScavTrap(dia.name)
{
	*this = dia;
	std::cout << "diamond '" << dia.name << "' copy constructor called";
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Diamond Trap " << this->name << " Destroued\n";
}

DiamondTrap&	DiamondTrap::operator = (const DiamondTrap& dia)
{
	if (&dia != this)
	{
		this->hp = dia.hp;
		this->energy = dia.energy;
		this->damage = dia.damage;
		this->name = dia.name;
	}
	return (*this);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "diamond name: " << this->name << "clap name: " << ClapTrap::name << std::endl;
}

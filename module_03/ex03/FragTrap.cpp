/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:27:26 by yridgway          #+#    #+#             */
/*   Updated: 2023/04/16 21:35:37 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	this->hp = 100;
	this->energy = 100;
	this->damage = 30;
	std::cout << "Frag Trap " << this->name << " Created\n";
}

FragTrap::FragTrap(const FragTrap& frag) : ClapTrap(frag.name)
{
	std::cout << "Frag Trap Created\n";
	*this = frag;
}

FragTrap::~FragTrap()
{
	std::cout << "Frag Trap " << this->name << " Destroyed\n";
}

FragTrap&	FragTrap::operator = (const FragTrap& frag)
{
	if (&frag != this)
	{
		this->hp = frag.hp;
		this->energy = frag.energy;
		this->damage = frag.damage;
		this->name = frag.name;
	}
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "\n🙌\n\n";
}
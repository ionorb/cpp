/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:33:38 by yridgway          #+#    #+#             */
/*   Updated: 2023/04/17 18:41:00 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void	conflict(ClapTrap& attacker, ClapTrap& target)
{
	attacker.attack(target.getName());
	target.takeDamage(attacker.getDamage());
}

int	main()
{
	DiamondTrap	dia("dia");

	for (int i = 0; i < 10; i++)
		dia.beRepaired(1);
	dia.attack("booy");
	for (int i = 0; i < 11; i++)
		dia.takeDamage(10);
	dia.attack("boo");
	return 0;
}
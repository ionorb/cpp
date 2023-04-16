/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:33:38 by yridgway          #+#    #+#             */
/*   Updated: 2023/04/16 21:18:15 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void	conflict(ClapTrap& attacker, ClapTrap& target)
{
	attacker.attack(target.getName());
	target.takeDamage(attacker.getDamage());
}

int	main()
{
	ClapTrap	bobby("bobby");
	ClapTrap	jeff("jeff");
	ScavTrap	scavy("scavy");
	
	conflict(bobby, jeff);
	for (int i = 0; i < 10; i++)
		bobby.beRepaired(1);
	for (int i = 0; i < 10; i++)
	{
		jeff.takeDamage(2);
		bobby.takeDamage(2);
	}
	scavy.guardGate();
	scavy.attack("bbanana");
	return 0;
}
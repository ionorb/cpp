/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:33:38 by yridgway          #+#    #+#             */
/*   Updated: 2023/04/16 20:23:15 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	conflict(ClapTrap& attacker, ClapTrap& target)
{
	attacker.attack(target.getName());
	target.takeDamage(attacker.getDamage());
}

int	main()
{
	ClapTrap	bobby("bobby");
	ClapTrap	jeff("jeff");
	
	conflict(bobby, jeff);
	for (int i = 0; i < 10; i++)
		bobby.beRepaired(1);
	for (int i = 0; i < 10; i++)
	{
		jeff.takeDamage(2);
		bobby.takeDamage(2);
	}
	return 0;
}
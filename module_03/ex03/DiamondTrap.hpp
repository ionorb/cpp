/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:27:18 by yridgway          #+#    #+#             */
/*   Updated: 2023/04/17 18:43:25 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

class	DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& dia);
		virtual ~DiamondTrap(void);
		DiamondTrap&	operator = (const DiamondTrap& dia);
		void attack(const std::string& target);
		void	whoAmI();
	private:
		std::string	name;
		int	hp;
		int	energy;
		int	damage;
};

#endif

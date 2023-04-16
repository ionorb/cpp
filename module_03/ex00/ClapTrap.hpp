/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:33:59 by yridgway          #+#    #+#             */
/*   Updated: 2023/04/16 20:11:56 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
#include <iostream>

class	ClapTrap
{

	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& clap);
		~ClapTrap();
		ClapTrap&	operator = (const ClapTrap& clap);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		int				getHP();
		int				getDamage();
		int				getEnergy();
		std::string		getName();
	private:
		int			hp;
		int			energy;
		int			damage;
		std::string	name;

};

#endif

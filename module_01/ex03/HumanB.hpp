/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <yoel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:56:41 by yoel              #+#    #+#             */
/*   Updated: 2023/04/12 20:59:30 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <string>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string new_name);
		~HumanB();
		void	attack(void);
		void	setWeapon(Weapon& new_weapon);

	private:
		Weapon		*weapon;
		std::string name;
};

#endif
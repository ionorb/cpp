/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <yoel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:54:05 by yoel              #+#    #+#             */
/*   Updated: 2023/04/12 20:58:11 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include <string>
#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string new_name, Weapon& new_weapon);
		~HumanA();
		void	attack(void);

	private:
		Weapon		*weapon;
		std::string name;
};

#endif

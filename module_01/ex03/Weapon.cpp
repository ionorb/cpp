/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <yoel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:04:38 by yoel              #+#    #+#             */
/*   Updated: 2023/04/12 20:53:45 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string new_type)
{
	type = new_type;
	std::cout << "weapon created\n";
}

Weapon::~Weapon(void)
{
	std::cout << "weapon \"" << type << "\" destroyed\n";
}

const std::string&	Weapon::getType(void)
{
	// std::string&	ref = type;

	// return (ref);
	return (type);
}

void	Weapon::setType(std::string new_type)
{
	type = new_type;
}

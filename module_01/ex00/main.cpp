/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <yoel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:30:56 by yoel              #+#    #+#             */
/*   Updated: 2023/04/12 15:44:36 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie* zombie;
	
	zombie = newZombie("heapy");
	zombie->announce();
	delete zombie;
	randomChump("stacky");
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <yoel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:19:02 by yoel              #+#    #+#             */
/*   Updated: 2023/04/12 23:59:15 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	Harl	harl;

	if (ac == 2)
	{
		harl.complain(av[1]);
	}
	else
		return (std::cerr << "wrong num of args\n", 1);
	return (0);
}
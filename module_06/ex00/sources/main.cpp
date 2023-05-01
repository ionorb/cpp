/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <yoel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:58:36 by yoel              #+#    #+#             */
/*   Updated: 2023/05/01 20:23:12 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

char ScalarConverter::character;
int ScalarConverter::integer;
float ScalarConverter::fpoint;
double ScalarConverter::dpoint;

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		ScalarConverter::convert(av[1]);
		// std::cout << av[1] << std::endl;
	}
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <yoel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:27:10 by yoel              #+#    #+#             */
/*   Updated: 2023/04/11 20:01:50 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>

int	main()
{
	// int	input;
	std::string field[4];

	// field[0].shrink_to_fit()
	for (int i = 0; i < 4; i++)
	{
		std::cout << "first name: ";
		std::getline(std::cin, field[i]);
		// std::cout << std::setw(10);
	}
	std::cout << "|";
	for (int i = 0; i < 4; i++)
	{
		if (field[0].size() > 10)
		{
			field[i].resize(10);
			field[i][9] = '.';
		}
		std::cout << std::setw(10) << field[i] << "|";
	}
	return (0);
}

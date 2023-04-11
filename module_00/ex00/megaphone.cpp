/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <yoel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:15:05 by yoel              #+#    #+#             */
/*   Updated: 2023/04/11 18:43:07 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <cstdio>

// int main(int ac, char **av)
// {
// 	if (ac == 1)
// 		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n", 0);
// 	for (int i = 1; av[i]; i++)
// 	{
// 		for (int j = 0; av[i][j]; j++)
// 			std::cout << (char)toupper(av[i][j]);
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }

int main(int ac, char **av)
{
	if (ac == 1)
		return (puts("* LOUD AND UNBEARABLE FEEDBACK NOISE *"), 0);
	for (int i = 1; av[i]; i++)
	{
		for (int j = 0; av[i][j]; j++)
			putchar(toupper(av[i][j]));
	}
	std::cout << std::endl;
	return (0);
}
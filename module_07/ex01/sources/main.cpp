/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:02:36 by codespace         #+#    #+#             */
/*   Updated: 2023/05/10 17:16:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	addOne(int& i)
{
	i++;
}

int	main(void)
{
	int i[100];

	for (int j = 0; j < 100; j++)
		i[j] = 100 - j;
	::iter(i, 100, *addOne);
	for (int j = 0; j < 100; j++)
		std::cout << i[j] << ", ";
	std::cout << std::endl;
	return (0);
}
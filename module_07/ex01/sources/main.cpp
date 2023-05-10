/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:02:36 by codespace         #+#    #+#             */
/*   Updated: 2023/05/10 18:20:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	addOne(int& i)
{
	i++;
}

void	capitalize(std::string& i)
{
	for (std::size_t j = 0; j < i.size(); j++)
	{
		if (j == 0 || i[j - 1] == ' ')
			i[j] = toupper(i[j]);
	}
}

void	scramble(std::string& i)
{
	std::srand((unsigned)time(NULL) * (unsigned)clock());
	char		tmp;
	std::size_t	index1, index2;

	for (std::size_t j = 0; j < i.size(); j++)
	{
		index1 = rand() % i.size();
		index2 = rand() % i.size();
		tmp = i[index1];
		i[index1] = i[index2];
		i[index2] = tmp;
	}
}

int	main(void)
{
	{
		int i[100];

		for (int j = 0; j < 100; j++)
			i[j] = 100 - j;
		::iter(i, 100, *addOne);
		for (int j = 0; j < 100; j++)
			std::cout << i[j] << ", ";
		std::cout << std::endl;
	}
	{
		std::string	i[100];
		
		for (int j = 0; j < 100; j++)
			i[j] = "banana pancakes";
		::iter(i, 100, *scramble);
		for (int j = 0; j < 100; j++)
			std::cout << i[j] << ", ";
		std::cout << std::endl;
	}
	return (0);
}
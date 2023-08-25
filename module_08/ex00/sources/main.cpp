/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:46:48 by codespace         #+#    #+#             */
/*   Updated: 2023/08/25 15:20:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <list>
#include <deque>

# define N 5

int	main(int ac, char **av) 
{
	int tofind = 1;

	if (ac == 2)
		tofind = atoi(av[1]);

	int	arr[N] = {1, 3, 4, 2, 5};

	std::cout << "array: ";
	for (size_t i = 0; i < N; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	std::vector<int> vec(arr, arr + N);
	std::list<int> lst(arr, arr + N);
	std::deque<int> deq(arr, arr + N);

	::easyfind(vec, tofind);
	::easyfind(lst, tofind);
	::easyfind(deq, tofind);

	return 0;
}

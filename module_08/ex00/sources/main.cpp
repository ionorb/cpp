/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:46:48 by codespace         #+#    #+#             */
/*   Updated: 2023/08/19 11:27:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <list>
#include <deque>

int	main(int ac, char **av) 
{
	int tofind = 1;
	if (ac == 2)
		tofind = atoi(av[1]);
	int	n = 5;
	int	arr[n] = {1, 3, 4, 2, 5};
	std::vector<int> vec(arr, arr + n);
	std::list<int> lst(arr, arr + n);
	std::deque<int> deq(arr, arr + n);

	::easyfind(vec, tofind);
	::easyfind(lst, tofind);
	::easyfind(deq, tofind);
	return 0;
}

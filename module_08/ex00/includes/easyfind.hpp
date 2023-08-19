/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:42:13 by codespace         #+#    #+#             */
/*   Updated: 2023/08/19 11:28:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <cstddef>
#include <iostream>


template <typename T> void easyfind(T container, int number)
{
	size_t	i = 0;
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
	{
		if (*it == number)
		{
			std::cout << "Integer \'" << number \
			<< "\' was found in the container at index: " \
			<< i << std::endl;
			return ;
		}
		i++;
	}
	std::cout << "Integer \'" << number << "\' was not found in the container" << std::endl;
}

#endif

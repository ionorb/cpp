/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:42:13 by codespace         #+#    #+#             */
/*   Updated: 2023/08/25 15:23:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <cstddef>
#include <iostream>
#include <algorithm>


template <typename T> void easyfind(T container, int number)
{
	typename T::iterator it = std::find(container.begin(), container.end(), number);
	if (it != container.end())
	{		
		std::cout << "Integer \'" << number \
				  << "\' was found in the container at index: " \
				  << std::distance(container.begin(), it) << std::endl;
	}
	else
		std::cout << "Integer \'" << number << "\' was not found in the container" << std::endl;
}

#endif

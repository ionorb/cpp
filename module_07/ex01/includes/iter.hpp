/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:41:57 by codespace         #+#    #+#             */
/*   Updated: 2023/05/10 17:13:52 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
#include <iostream>

template<typename T> void iter(T* arr, unsigned long size, void (*func)(T&))
{
	if (!arr)
	{
		std::cerr << "invalid array pointer!\n";
		return ;
	}
	for (unsigned long i = 0; i < size; i++)
		func(arr[i]);
}

#endif

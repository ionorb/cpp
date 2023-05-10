/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:35:41 by codespace         #+#    #+#             */
/*   Updated: 2023/05/10 19:39:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	std::cout << "Array Construction with no params\n";
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	std::cout << "Array Construction with \'n\'\n";
}
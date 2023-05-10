/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:35:41 by codespace         #+#    #+#             */
/*   Updated: 2023/05/10 20:31:54 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	std::cout << "Array Construction with no params\n";
	this->n = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	std::cout << "Array Construction with \'n\'\n";
	this->arr = new T[n];
	this->n = n;
}

template <typename T>
unsigned int Array<T>::size(void)
{
	return (this->n);
}

template <typename T>
Array<T>::Array(const T& copy) : Array(copy.n)
{
	for (unsigned int i = 0; i < this->n; i++)
		this->arr[i] = copy.arr[i];
}

template <typename T>
T&	Array<T>::operator = (const T& copy)
{
	for (unsigned int i = 0; i < this->n; i++)
		this->arr[i] = copy.arr[i];
	return (*this);
}

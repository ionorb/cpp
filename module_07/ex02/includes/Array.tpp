/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:35:41 by codespace         #+#    #+#             */
/*   Updated: 2023/05/15 22:07:27 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : len(0)
{
	std::cout << "Array Construction with no params\n";
	this->arr = new T[0];
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Array Destruction\n";
	delete[] this->arr;
}

template <typename T>
Array<T>::Array(unsigned int n) : len(n)
{
	std::cout << "Array Construction with \'n\'\n";
	this->arr = new T[n];
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return (this->n);
}

template <typename T>
Array<T>::Array(const Array& copy) : len(copy.len)
{
	this->arr = new T[this->len];
	for (unsigned int i = 0; i < this->n; i++)
		this->arr[i] = copy.arr[i];
}

template <typename T>
Array<T>&	Array<T>::operator = (const Array& copy)
{
	if (this == copy)
		return (*this);
	delete[] this->arr;
	this->arr = new T[this->len];
	for (unsigned int i = 0; i < this->len; i++)
		this->arr[i] = copy.arr[i];
	return (*this);
}

template <typename T>
T&	Array<T>::operator [] (int index)
{
	(void)index;
	return (*this);
}

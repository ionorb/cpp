/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:35:41 by codespace         #+#    #+#             */
/*   Updated: 2023/08/19 10:14:24 by codespace        ###   ########.fr       */
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
	return (this->len);
}

template <typename T>
Array<T>::Array(const Array& copy) : len(copy.len)
{
	this->arr = new T[this->len];
	for (unsigned int i = 0; i < this->len; i++)
		this->arr[i] = copy.arr[i];
}

template <typename T>
Array<T>&	Array<T>::operator = (const Array& copy)
{
	len = copy.len;
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
	if (index < 0)
		throw std::out_of_range("negative index");
	if ((unsigned int)index >= this->len)
		throw std::out_of_range("index too large");
	return this->arr[index];
}

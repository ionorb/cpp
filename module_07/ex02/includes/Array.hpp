/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:52:31 by codespace         #+#    #+#             */
/*   Updated: 2023/08/19 10:18:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
#include <iostream>

template <typename T>
class Array
{
	public:
		Array();
		~Array();
		Array(unsigned int n);
		Array(const Array& copy);
		Array<T>&		operator = (const Array& copy);
		T&				operator[](int);
		unsigned int	size(void) const;
		unsigned int	len;
	private:
		T				*arr;
};

#include "Array.tpp"
#endif

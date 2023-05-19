/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:52:31 by codespace         #+#    #+#             */
/*   Updated: 2023/05/15 22:07:44 by yridgway         ###   ########.fr       */
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
		T				*arr;
	// private:
};

#include "Array.tpp"
#endif

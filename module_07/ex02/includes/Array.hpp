/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:52:31 by codespace         #+#    #+#             */
/*   Updated: 2023/05/10 20:35:58 by codespace        ###   ########.fr       */
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
		Array(unsigned int n);
		Array(const T& copy);
		T&	operator = (const T& copy);
		T&	operator[](int);
		unsigned int	size(void);
	private:
		unsigned int n;
		T	*agrr;
		
};

#include "Array.tpp"
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:42:13 by codespace         #+#    #+#             */
/*   Updated: 2023/05/10 14:54:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T> void swap(T first, T second)
{
	T temp = T(first);
	first = T(second);
	second = T(temp);
}

template <typename T> T min(T first, T second)
{
	if (first < second)
		return (first);
	return (second);
}

template <typename T> T max(T first, T second)
{
	if (first > second)
		return (first);
	return (second);
}

#endif

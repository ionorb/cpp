/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:17:48 by codespace         #+#    #+#             */
/*   Updated: 2023/05/10 11:52:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer Default Constrctor\n";
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	(void)ptr;
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	(void)raw;
	return (reinterpret_cast<Data*>(raw));
}

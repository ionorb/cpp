/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <myaccount@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:45:15 by myaccount         #+#    #+#             */
/*   Updated: 2023/04/19 15:17:41 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat object created\n";
	this->type = "Cat";
}

Cat::~Cat(void)
{
	std::cout << "Cat object destroyed\n";
}

Cat::Cat(const Cat& copy)
{
	std::cout << "Cat object copied\n";
	*this = copy;
}

Cat&	Cat::operator = (const Cat& copy)
{
	std::cout << "Cat object assigned\n";
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:45:15 by myaccount         #+#    #+#             */
/*   Updated: 2023/04/21 14:23:42 by codespace        ###   ########.fr       */
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

Cat::Cat(const Cat& copy) : Animal()
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

void	Cat::makeSound(void) const
{
	std::cout << "*meeowww*" << std::endl;
}

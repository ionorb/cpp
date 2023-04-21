/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:45:24 by myaccount         #+#    #+#             */
/*   Updated: 2023/04/21 14:23:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog object created\n";
	this->type = "Dog";
}

Dog::~Dog(void)
{
	std::cout << "Dog object destroyed\n";
}

Dog::Dog(const Dog& copy) : Animal()
{
	std::cout << "Dog object copied\n";
	*this = copy;
}

Dog&	Dog::operator = (const Dog& copy)
{
	std::cout << "Dog object assigned\n";
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "*BARK*" << std::endl;
}

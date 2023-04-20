/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <myaccount@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:45:23 by myaccount         #+#    #+#             */
/*   Updated: 2023/04/20 20:50:15 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal object created\n";
	this->type = "";
}

Animal::~Animal(void)
{
	std::cout << "Animal object destroyed\n";
}

Animal::Animal(const Animal& copy)
{
	std::cout << "Animal object copied\n";
	*this = copy;
}

Animal&	Animal::operator = (const Animal& copy)
{
	std::cout << "Animal object assigned\n";
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "*animal sounds*" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

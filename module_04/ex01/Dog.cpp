/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <myaccount@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:45:24 by myaccount         #+#    #+#             */
/*   Updated: 2023/04/19 19:08:14 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog object created\n";
	this->type = "Dog";
	this->brain = new Brain;
}

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << "Dog object destroyed\n";
}

Dog::Dog(const Dog& copy)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <myaccount@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:45:24 by myaccount         #+#    #+#             */
/*   Updated: 2023/04/19 18:41:04 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog object created\n";
	this->brain = new Brain;
	this->type = "Dog";
}

Dog::~Dog(void)
{
	std::cout << "Dog object destroyed\n";
	delete this->brain;
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

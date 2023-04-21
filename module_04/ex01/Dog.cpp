/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:45:24 by myaccount         #+#    #+#             */
/*   Updated: 2023/04/21 16:34:20 by codespace        ###   ########.fr       */
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

Dog::Dog(const Dog& copy) : Animal()
{
	std::cout << "Dog object copied\n";
	this->type = "Dog";
	this->brain = new Brain;
	*this->brain = *copy.brain;
}

Dog&	Dog::operator = (const Dog& copy)
{
	std::cout << "Dog object assigned\n";
	if (this != &copy)
	{
		this->type = copy.type;
		*this->brain = *copy.brain;
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << this->type << ": *BARK*" << std::endl;
}

void	Dog::printBrain(void)
{
	for (int i = 0; i < 99; i++)
		std::cout << this->brain->getIdeas()[i] << ", ";
	std::cout << this->brain->getIdeas()[99] << "\n";
}

void	Dog::setBrain(std::string idea)
{
	this->brain->setIdeas(idea);
}

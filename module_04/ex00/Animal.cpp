/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <myaccount@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:45:23 by myaccount         #+#    #+#             */
/*   Updated: 2023/04/19 15:30:30 by myaccount        ###   ########.fr       */
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

void	Animal::makeSound(void)
{
	std::string	sound;
	
	if (this->type == "Dog")
		sound = "BARK";
	else if (this->type == "Cat")
		sound = "meow";
	else
		sound = "animal sounds";
	std::cout << "*" << sound << "*" << std::endl;
}
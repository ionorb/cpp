/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <myaccount@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:45:23 by myaccount         #+#    #+#             */
/*   Updated: 2023/04/19 18:12:56 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal object created\n";
	this->type = "";
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal object destroyed\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	std::cout << "WrongAnimal object copied\n";
	*this = copy;
}

WrongAnimal&	WrongAnimal::operator = (const WrongAnimal& copy)
{
	std::cout << "WrongAnimal object assigned\n";
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "*Wronganimal sounds*" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}

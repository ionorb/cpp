/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <myaccount@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:45:15 by myaccount         #+#    #+#             */
/*   Updated: 2023/04/19 19:08:11 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat object created\n";
	this->type = "Cat";
	this->brain = new Brain;
}

Cat::~Cat(void)
{
	delete this->brain;
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

void	Cat::makeSound(void) const
{
	std::cout << "*meeowww*" << std::endl;
}

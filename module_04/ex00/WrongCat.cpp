/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <myaccount@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:45:15 by myaccount         #+#    #+#             */
/*   Updated: 2023/04/19 18:13:09 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat object created\n";
	this->type = "WrongCat";
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat object destroyed\n";
}

WrongCat::WrongCat(const WrongCat& copy)
{
	std::cout << "WrongCat object copied\n";
	*this = copy;
}

WrongCat&	WrongCat::operator = (const WrongCat& copy)
{
	std::cout << "WrongCat object assigned\n";
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "*meeowww*" << std::endl;
}

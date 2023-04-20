/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <myaccount@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:59:38 by myaccount         #+#    #+#             */
/*   Updated: 2023/04/19 19:05:56 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "brain created\n";
}

Brain::~Brain()
{
	std::cout << "brain destroyed\n";
}

Brain::Brain(const Brain& copy)
{
	std::cout << "brain is being copied\n";
	*this = copy;
}

Brain&	Brain::operator = (const Brain& copy)
{
	std::cout << "brain is being assigned\n";
	if (this != &copy)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = copy.ideas[i];
	}
	return (*this);
}

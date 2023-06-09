/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:59:38 by myaccount         #+#    #+#             */
/*   Updated: 2023/04/21 16:32:34 by codespace        ###   ########.fr       */
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

std::string*	Brain::getIdeas(void)
{
	return(this->ideas);
}

void	Brain::setIdeas(std::string idea)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = idea;
}

Brain::Brain(std::string idea)
{
	this->setIdeas(idea);
}

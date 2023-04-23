/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:31:21 by codespace         #+#    #+#             */
/*   Updated: 2023/04/23 19:15:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	std::cout << "Ice Constructor\n";
	this->type = "ice"; //hmm
}

Ice::Ice(std::string const & type)
{
	(void)type;
	// std::cout << "Ice construct with type\n";
	this->type = type; //hmm
}

Ice::~Ice()
{
	std::cout << "Ice Destructor\n";
}

Ice::Ice(const Ice& copy) : AMateria(copy.type)
{
	std::cout << "Ice COPY Constructor\n";
	// *this = copy;
	(void)copy;
	// this->type = copy.type;
}

Ice&	Ice::operator = (const Ice& copy)
{
	// std::cout << "Ice Assignment\n";
	// if (this != &copy)
	// 	*this = *copy.clone();
	(void)copy;
	return (*this);
}

Ice*	Ice::clone() const
{
	return (new Ice("ice"));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "Ice: \'* shoots an ice bolt at " \
			  << target.getName() << " *\'\n";
}

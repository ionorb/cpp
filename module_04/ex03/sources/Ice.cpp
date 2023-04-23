/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:31:21 by codespace         #+#    #+#             */
/*   Updated: 2023/04/22 18:44:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	std::cout << "Ice Constructor\n";
}

Ice::Ice(std::string const & type)
{
	std::cout << "Ice construct with type\n";
	this->type = type; //hmm
}

Ice::~Ice()
{
	std::cout << "Ice Destructor\n";
}

Ice::Ice(const Ice& copy)
{
	std::cout << "Ice COPY Constructor\n";
	*this = copy;
	// this->type = copy.type;
}

Ice&	Ice::operator = (const Ice& copy)
{
	std::cout << "Ice Assignment\n";
	if (this != &copy)
		*this = *copy.clone();
	return (*this);
}

std::string const&	Ice::getType() const
{
	return (this->type);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "Ice: \'* shoots an ice bolt at " \
			  << target.getName() << " *\'\n";
}
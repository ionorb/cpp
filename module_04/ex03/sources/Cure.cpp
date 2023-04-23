/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:46:00 by codespace         #+#    #+#             */
/*   Updated: 2023/04/23 19:15:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	std::cout << "Cure Constructor\n";
	this->type = "cure"; //hmm
}

Cure::Cure(std::string const & type)
{
	(void)type;
	std::cout << "Cure construct with type\n";
	this->type = type; //hmm
}

Cure::~Cure()
{
	std::cout << "Cure Destructor\n";
}

Cure::Cure(const Cure& copy) : AMateria(copy.type)
{
	std::cout << "Cure COPY Constructor\n";
	// *this = copy;
	// this->type = copy.type;
	(void)copy;
}

Cure&	Cure::operator = (const Cure& copy)
{
	std::cout << "Cure Assignment\n";
	// if (this != &copy)
	// {
	// 	*this = *copy.clone();
	// }
	(void)copy;
	return (*this);
}

Cure*	Cure::clone() const
{
	return (new Cure("cure"));
}

void	Cure::use(ICharacter& target)
{
	std::cout << "Cure: \'* heals " \
			  << target.getName() \
			  << "'s wounds *\'\n";
}
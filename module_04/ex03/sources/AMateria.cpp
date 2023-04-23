/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:18:12 by codespace         #+#    #+#             */
/*   Updated: 2023/04/23 13:20:22 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria Constructor\n";
}

AMateria::AMateria(std::string const & type)
{
	std::cout << "AMateria construct with type\n";
	this->type = type; //hmm
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor\n";
}

AMateria::AMateria(const AMateria& copy)
{
	std::cout << "AMateria COPY Constructor\n";
	*this = copy;
	// this->type = copy.type;
}

AMateria&	AMateria::operator = (const AMateria& copy)
{
	std::cout << "AMateria Assignment\n";
	if (this != &copy)
		*this = *copy.clone();
	return (*this);
}

std::string const&	AMateria::getType() const
{
	return (this->type);
}

void	AMateria::use(ICharacter& target)
{
	// std::cout << "General Materia: \'* uses " << this->type << " *\'\n";
	(void)target;
}

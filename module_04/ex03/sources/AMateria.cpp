/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:18:12 by codespace         #+#    #+#             */
/*   Updated: 2023/04/22 17:23:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria Constructor\n";
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor\n";
}

AMateria::AMateria(const AMateria& copy)
{
	std::cout << "AMateria COPY Constructor\n";
	*this = copy;
}

AMateria&	AMateria::operator = (const AMateria& copy)
{
	std::cout << "AMateria Assignment\n";
}

AMateria::AMateria(std::string const & type)
{
	std::cout << "AMateria set type\n";
	
}

std::string const&	AMateria::getType() const
{
	return (this->type);
}

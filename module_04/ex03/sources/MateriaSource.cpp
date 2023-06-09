/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 13:29:14 by codespace         #+#    #+#             */
/*   Updated: 2023/04/23 19:46:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource construct\n";
	for (int i = 0; i < 4; i++)
		this->learned[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete this->learned[i];
	std::cout << "MateriaSource Destructor\n";
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	std::cout << "MateriaSource COPY Constructor\n";
	for (int i = 0; i < 4; i++)
		this->learned[i] = NULL;
	*this = copy;
}

MateriaSource&	MateriaSource::operator = (const MateriaSource& copy)
{
	std::cout << "MateriaSource Assignment\n";
	if (this != &copy)
	{
		for (int i = 0; i < 4; i++)
			delete this->learned[i], this->learned[i] = NULL;
		for (int i = 0; i < 4 && copy.learned[i]; i++)
			this->learned[i] = copy.learned[i]->clone();
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* ptr)
{
	int	i = 0;

	if (!ptr)
		return ;
	while (i < 4 && this->learned[i])
		i++;
	if (i < 4 && !this->learned[i] && ptr)
	{
		this->learned[i] = ptr;
		std::cout << ptr->getType() << " learned!\n";
	}
	else
		std::cout << "cannot learn more than four items!\n", delete ptr;
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	int	i = 0;
	
	while (i < 4 && this->learned[i])
	{
		if (this->learned[i]->getType() == type)
			return (this->learned[i]->clone());
		i++;
	}
	std::cout << "materia " << type << " not found\n";
	return (0);
}

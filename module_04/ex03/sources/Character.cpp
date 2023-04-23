/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:49:21 by codespace         #+#    #+#             */
/*   Updated: 2023/04/22 20:23:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	std::cout << "Character Constructor\n";
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(std::string const& name) : name(name)
{
	std::cout << "Character construct with name\n";
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete this->inventory[i];
	std::cout << "Character Destructor\n";
}

Character::Character(const Character& copy)
{
	std::cout << "Character COPY Constructor\n";
	*this = copy;
}

Character&	Character::operator = (const Character& copy)
{
	std::cout << "Character Assignment\n";
	if (this != &copy)
	{
		*this = *copy.clone();
	}
	return (*this);
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && idx >= 0 && this->inventory[idx])
		this->inventory[idx]->use(target);
	else if (idx > 3 || idx < 0)
		std::cout << "INVALID INDEX\n";
	else
		std::cout << "No item at " << idx << "\n";
}

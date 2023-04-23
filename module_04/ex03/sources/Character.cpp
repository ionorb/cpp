/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:49:21 by codespace         #+#    #+#             */
/*   Updated: 2023/04/23 17:04:55 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("default")
{
	std::cout << "Character Constructor\n";
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	// num_items = 0;
}

Character::Character(std::string const& name) : name(name)
{
	std::cout << "Character construct with name\n";
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	// num_items = 0;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
			delete this->inventory[i];
	std::cout << "Character Destructor\n";
}

Character::Character(const Character& copy) : name(copy.name)
{
	std::cout << "Character COPY Constructor\n";
	for (int i = 0; i < 4; i++)
	{
		delete this->inventory[i];
		this->inventory[i] = copy.inventory[i];
	}
	// this->num_items = copy.num_items;
}

Character&	Character::operator = (const Character& copy)
{
	std::cout << "Character Assignment\n";
	if (this != &copy)
	{
		for (int i = 0; i < 4; i++)
		{
			delete this->inventory[i];
			this->inventory[i] = copy.inventory[i];
		}
		// this->num_items = copy.num_items;
	}
	return (*this);
}

std::string const&	Character::getName() const
{
	return (this->name);
}

void	Character::equip(AMateria* m)
{
	int	i = 0;

	if (!m)
	{
		std::cout << "error: invalid materia\n";
		return ;
	}
	while (i < 4 && this->inventory[i])
		i++;
	if (i < 4 && !this->inventory[i])
	{
		this->inventory[i] = m;
		std::cout << m->getType() << " equiped\n";
	}
	else
		std::cout << m->getType() << " inventory full!\n";
}

void	Character::unequip(int idx)
{
	if (idx < 4 && idx >= 0 && this->inventory[idx])
	{
		delete this->inventory[idx]; // add to llist instead of deleting
		this->inventory[idx] = NULL;
	}
	else if (idx > 3 || idx < 0)
		std::cout << "INVALID INDEX\n";
	else
		std::cout << "No item in slot " << idx << "!\n";
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && idx >= 0 && this->inventory[idx])
		(this->inventory[idx])->use(target);
	else if (idx > 3 || idx < 0)
		std::cout << "INVALID INDEX\n";
	else
		std::cout << "No item in slot " << idx << "!\n";
}

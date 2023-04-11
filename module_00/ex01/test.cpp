/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <yoel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:27:10 by yoel              #+#    #+#             */
/*   Updated: 2023/04/11 22:43:54 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact(void)
{
	std::cout << "contact created!" << std::endl;
}

PhoneBook::PhoneBook(void)
{
	std::cout << "phonebook created!" << std::endl;
}

Contact::~Contact(void)
{
	std::cout << "contact destroyed!" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "phonebook destroyed!" << std::endl;
}

t_info Contact::getinfo()
{
	return (info);
}

void Contact::setinfo(t_info new_info)
{
	info = new_info;
}

Contact PhoneBook::getcontact(int index)
{
	return (contacts[index]);
}

void PhoneBook::addcontact(int index, Contact new_contact)
{
	contacts[index] = new_contact;
}

void	search_phonebook(void)
{
	puts("searching phonebook...");
}

void	add_info(void)
{
	t_info new_info;

	puts("adding info...");
	std::cout << "first name: ";
	std::cout << "last name: ";
	std::cout << "nickname: ";
	std::cout << "phone number: ";
	std::cout << "darkest secret: ";
	// for (int i = 0; i < 4; i++)
	// {
	// 	std::cout << "first name: ";
	// 	getline(std::cin, field[i]);
	// 	// std::cout << std::setw(10);
	// }
	// std::cout << "|";
	// for (int i = 0; i < 4; i++)
	// {
	// 	if (field[0].size() > 10)
	// 	{
	// 		field[i].resize(10);
	// 		field[i][9] = '.';
	// 	}
	// 	std::cout << std::setw(10) << field[i] << "|";
	// }
}

int	main()
{
	// int fin = 1; 
	std::string input;

	do {
		getline(std::cin, input);
		if (!input.compare("ADD"))
			add_info();
		if (!input.compare("SEARCH"))
			search_phonebook();
		else if (input.compare("EXIT"))
			std::cout << \
			"Please enter a valid command: \"ADD\", \"SEARCH\" or \"EXIT\"\n";
	} while (input.compare("EXIT"));
	return (0);
}

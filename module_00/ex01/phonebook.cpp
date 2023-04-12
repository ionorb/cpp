/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <yoel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:27:10 by yoel              #+#    #+#             */
/*   Updated: 2023/04/12 11:41:26 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

//constructors
Contact::Contact(void)
{}

PhoneBook::PhoneBook(void)
{
	number_of_contacts = 0;
}

//destructors
Contact::~Contact(void)
{}

PhoneBook::~PhoneBook(void)
{}

//gets and sets
t_info Contact::getinfo()
{
	return (info);
}

Contact PhoneBook::getcontact(int index)
{
	return (contacts[index]);
}

void PhoneBook::addcontact(int index, Contact new_contact)
{
	contacts[index] = new_contact;
	number_of_contacts++;
}

int PhoneBook::getnumcontacts(void)
{
	return (number_of_contacts);
}

std::string input_loop(std::string prompt)
{
	std::string	info;

	do{
		std::cout << prompt + ": ";
		getline(std::cin, info);
	} while (info.find_first_not_of("\t\n\v\f\r ") == std::string::npos);
	return (info);
}

void Contact::setinfo(int index)
{
	std::string	input;

	info.index = index;
	info.first_name = input_loop("first name");
	info.last_name = input_loop("last name");
	info.nickname = input_loop("nickname");
	info.phone_number = input_loop("phone number");
	info.darkest_secret = input_loop("darkest secret");
}

void	display_column(std::string content)
{
	if (content.size() > 10)
	{
		content.resize(10);
		content[9] = '.';
	}
	std::cout << std::setw(10) << content << "|";
}

//main functions
void	search_phonebook(PhoneBook phonebook)
{
	t_info	info;
	int		index;
	int		num_contacts = phonebook.getnumcontacts();

	if (num_contacts == 0)
		return (void)puts("no contacts yet!");
	puts("searching phonebook...");
	for (int i = 0; i < 8 && i < num_contacts; i++)
	{
		std::cout << "|";
		info = phonebook.getcontact(i).getinfo();
		std::cout << std::setw(10) << info.index << "|";
		display_column(info.first_name);
		display_column(info.last_name);
		display_column(info.nickname);
		std::cout << std::endl;
	}
	index = input_loop("enter index of contact you want to see")[0] - '0';
	if (index < 0 || index > 8 || index >= num_contacts)
		return (void)puts("index out of range");
	info = phonebook.getcontact(index).getinfo();
	std::cout << "first name: " << info.first_name << std::endl;
	std::cout << "last name: " << info.last_name << std::endl;
	std::cout << "nickname: " << info.nickname << std::endl;
	std::cout << "phone number: " << info.phone_number << std::endl;
	std::cout << "darkest secret: " << info.darkest_secret << std::endl;
}

Contact	create_contact(int index)
{
	Contact new_contact;

	puts("adding info...");
	new_contact.setinfo(index);
	return (new_contact);
}

int	main()
{
	int			index, i;
	std::string	input;
	PhoneBook	phonebook;

	index = i = 0;
	do
	{
		index = i % 8;
		getline(std::cin, input);
		if (!input.compare("ADD"))
		{
			phonebook.addcontact(index, create_contact(index));
			i++;
		}
		else if (!input.compare("SEARCH"))
			search_phonebook(phonebook);
		else if (input.compare("EXIT"))
			std::cout << \
			"Please enter a valid command: \"ADD\", \"SEARCH\" or \"EXIT\"\n";
	} while (input.compare("EXIT"));
	return (0);
}

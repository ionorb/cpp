/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <yoel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:40:04 by yoel              #+#    #+#             */
/*   Updated: 2023/04/12 11:39:13 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_info
{
	int			index;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
} 	t_info;

class Contact {


public:

	Contact(void);
	~Contact(void);

	t_info	getinfo(void);
	void	setinfo(int index);


private:

	t_info info;


};

class PhoneBook {


public:

	PhoneBook(void);
	~PhoneBook(void);

	void	addcontact(int index, Contact new_contact);
	Contact	getcontact(int index);
	int		getnumcontacts(void);


private:

	Contact	contacts[8];
	int		number_of_contacts;


};

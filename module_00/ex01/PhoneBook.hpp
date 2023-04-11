/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <yoel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:40:04 by yoel              #+#    #+#             */
/*   Updated: 2023/04/11 22:38:43 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdio>

typedef struct s_info
{
	int index;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
} t_info;

class Contact
{
	public:
		Contact();
		~Contact();
		t_info getinfo();
		void setinfo(t_info new_info);
		// std::string getfirstname();
		// std::string getlastname();
		// std::string getnickname();
		// std::string getphonenumber();
		// std::string getsecret();
		// int getindex();
		// void setfirstname(std::string str);
		// void setlastname(std::string str);
		// void setnickname(std::string str);
		// void setphonenumber(std::string str);
		// void setsecret(std::string str);
	private:
		t_info info;
};

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void addcontact(int index, Contact new_contact);
		Contact getcontact(int index);
	private:
		Contact contacts[8];
};

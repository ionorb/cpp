/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:14:43 by codespace         #+#    #+#             */
/*   Updated: 2023/04/27 13:45:55 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Constrctor\n";
}

Intern::~Intern()
{
	std::cout << "Intern Default Destructor\n";
}

Intern::Intern(const Intern& copy)
{
	std::cout << "Intern Copy Constructor\n";
	(void)copy;
}

Intern&	Intern::operator = (const Intern& copy)
{
	std::cout << "Intern Assignment\n";
	(void)copy;
	return (*this);
}

AForm*	Intern::shrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::robotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::pardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(std::string form, std::string target)
{
	const int	N = 3;
	typedef		AForm*(Intern::*fPointer)(std::string);
	fPointer 	funcs[N] = \
	{&Intern::shrubbery, &Intern::robotomy, &Intern::pardon};
	std::string	forms[N] = \
	{"shrubbery creation", "robotomy request", "presidential pardon"};

	for (int i = 0; i < N; i++)
	{
		if (forms[i] == form)
		{
			std::cout << "Intern creates " << form << "\n";
			return (this->*funcs[i])(target);
		}
	}
	throw badForm;
}

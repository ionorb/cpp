/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:14:47 by codespace         #+#    #+#             */
/*   Updated: 2023/04/26 17:17:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
#include <iostream>
#include "GradeException.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ASCIItree.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern& copy);
		Intern&	operator = (const Intern& copy);
		AForm*	makeForm(std::string form, std::string target);
		AForm*	shrubbery(std::string target);
		AForm*	robotomy(std::string target);
		AForm*	pardon(std::string target);
		InexistantForm	badForm;
};

#endif

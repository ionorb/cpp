/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:58:06 by codespace         #+#    #+#             */
/*   Updated: 2023/04/26 16:00:37 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) \
: AForm("ShrubberyCreationForm", target, 145, 137) //_name(name), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "ShrubberyCreationForm Constrctor: (" << target << ")\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Default Destructor\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) \
: AForm("ShrubberyCreationForm", copy.getTarget(), 145, 137)
{
	std::cout << "ShrubberyCreationForm Copy Constructor\n";
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator = (const ShrubberyCreationForm& copy)
{
	std::cout << "ShrubberyCreationForm Assignment\n";
	(void)copy;
	return (*this);
}

void		ShrubberyCreationForm::action(void) const
{
	std::ofstream	outfile;
	std::string		filename = this->getTarget() + "_shrubbery";

	if (outfile.open(filename.c_str()), !outfile.is_open())
		std::cerr << "error creating outfile\n";
	outfile << TREE;
	outfile.close();
}

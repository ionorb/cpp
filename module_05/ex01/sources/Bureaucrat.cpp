/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:21:47 by codespace         #+#    #+#             */
/*   Updated: 2023/04/24 21:12:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat Default Constrctor\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat Constrctor with name and grade\n";
	if (grade < this->_max_grade)
		throw tooHigh;
	if (grade > this->_min_grade)
		throw tooLow;
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Default Destructor\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
	std::cout << "Bureaucrat Copy Constructor\n";
	this->_grade = copy._grade;

}

void	Bureaucrat::setGrade(int grade)
{
	this->_grade = grade;
}

Bureaucrat&	Bureaucrat::operator = (const Bureaucrat& copy)
{
	std::cout << "Bureaucrat Assignment\n";
	if (this != &copy)
		this->_grade = copy.getGrade();
	return (*this);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

std::ostream&	operator << (std::ostream& out, const Bureaucrat& a)
{
	out << a.getName() << ", bureaucrat grade " << a.getGrade() << std::endl;
	return (out);
}

void	Bureaucrat::upgrade(void)
{
	if (this->_grade - 1 < this->_max_grade)
		throw tooHigh;
	this->_grade -= 1;
}

void	Bureaucrat::downgrade(void)
{
	if (this->_grade + 1 > this->_min_grade)
		throw tooLow;
	this->_grade += 1;
}

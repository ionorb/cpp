/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:21:47 by codespace         #+#    #+#             */
/*   Updated: 2023/04/26 14:31:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat Default Constrctor\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat Constrctor with name and grade ";
	if (grade < this->_max_grade)
	{
		std::cout << "\nError: bureaucrat construction out of bounds\n";
		throw tooHigh;
	}
	if (grade > this->_min_grade)
	{
		std::cout << "\nError: bureaucrat construction out of bounds\n";
		throw tooLow;
	}
	std::cout << "(" << this->_name << ")\n";
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Default Destructor\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy.getName())
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

void	Bureaucrat::signForm(AForm& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << "\"" << this->_name << "\" signed \"" << form.getName() << "\"\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "\"" << this->_name << "\" couldn't sign \"" << form.getName() \
				  << "\" because \"" << this->_name << "\" " \
				  << e.what() << '\n';
	}
	
}

void	Bureaucrat::executeForm(const AForm& form) const
{
	try
	{
		form.execute(*this);
		std::cout << "\"" << this->_name << "\" executed \"" << form.getName() << "\"\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "\"" << this->_name << "\" couldn't execute \"" << form.getName() \
				  << "\" because " << e.what() << '\n';
	}
}
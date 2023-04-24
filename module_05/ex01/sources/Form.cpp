/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:21:27 by codespace         #+#    #+#             */
/*   Updated: 2023/04/24 23:18:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _sign_grade(1), _exec_grade(1)
{
	std::cout << "Form Default Constrctor\n";
	this->_is_signed = false;
}

Form::Form(std::string name, int sign_grade, int exec_grade) \
: _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "Form Constrctor with name\n";
	if (this->_sign_grade > _min_grade || this->_exec_grade > _min_grade)
	{
		std::cout << "Error: form construction out of bounds\n";
		throw tooLow;
	}
	if (this->_sign_grade < _max_grade || this->_exec_grade < _max_grade)
	{
		std::cout << "Error: form construction out of bounds\n";
		throw tooHigh;
	}
	this->_is_signed = false;
}

Form::~Form()
{
	std::cout << "Form Default Destructor\n";
}

Form::Form(const Form& copy) \
: _name(getName()), _sign_grade(getSignGrade()), _exec_grade(getExecGrade())
{
	std::cout << "Form Copy Constructor\n";
	this->_is_signed = copy.getSignStatus();
}

Form&	Form::operator = (const Form& copy)
{
	std::cout << "Form Assignment\n";
	if (this != &copy)
		this->_is_signed = copy.getSignStatus();
	return (*this);
}

std::ostream&	operator << (std::ostream& out, const Form& a)
{
	out << "Form:\nName: " << a.getName() \
		<< "\nSign Status: " << a.getSignStatus() \
		<< "\nSign Grade: " << a.getSignGrade() \
		<< "\nExec Grade: " << a.getExecGrade() << std::endl;
	return (out);
}

std::string	Form::getName() const
{
	return (this->_name);
}

bool	Form::getSignStatus() const
{
	return (this->_is_signed);
}

int		Form::getSignGrade() const
{
	return (this->_sign_grade);
}

int		Form::getExecGrade() const
{
	return (this->_exec_grade);
}

void	Form::beSigned(const Bureaucrat& signer)
{
	if (this->_sign_grade < signer.getGrade())
		throw tooLow;
	else
		this->_is_signed = true;
	std::cout << "\n\njflkdjsJFlkd:FKDJFLJFD\n\n";
}

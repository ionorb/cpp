/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:21:27 by codespace         #+#    #+#             */
/*   Updated: 2023/04/26 16:04:55 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _sign_grade(1), _exec_grade(1)
{
	std::cout << "AForm Default Constrctor\n";
	this->_is_signed = false;
}

AForm::AForm(std::string name, std::string target, int sign_grade, int exec_grade) \
: _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade), _target(target)
{
	(void)target;
	std::cout << "AForm Constrctor with name ";
	if (this->_sign_grade > _min_grade || this->_exec_grade > _min_grade)
	{
		std::cout << "\nError: Aform construction out of bounds\n";
		throw tooLow;
	}
	if (this->_sign_grade < _max_grade || this->_exec_grade < _max_grade)
	{
		std::cout << "\nError: Aform construction out of bounds\n";
		throw tooHigh;
	}
	std::cout << "(" << this->_name << ")\n";
	this->_is_signed = false;
}

AForm::~AForm()
{
	std::cout << "AForm Default Destructor\n";
}

AForm::AForm(const AForm& copy) \
: _name(copy.getName()), _sign_grade(copy.getSignGrade()), \
_exec_grade(getExecGrade()), _target(copy.getTarget())
{
	std::cout << "AForm Copy Constructor\n";
	this->_is_signed = copy.getSignStatus();
}

AForm&	AForm::operator = (const AForm& copy)
{
	std::cout << "AForm Assignment\n";
	if (this != &copy)
		this->_is_signed = copy.getSignStatus();
	return (*this);
}

std::ostream&	operator << (std::ostream& out, const AForm& a)
{
	out << a.getName() << ":" \
		<< "\nSign Status: " << a.getSignStatus() \
		<< "\nSign Grade: " << a.getSignGrade() \
		<< "\nExec Grade: " << a.getExecGrade() \
		<< "\nTarget: " << a.getTarget() << std::endl;
	return (out);
}

std::string	AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getSignStatus() const
{
	return (this->_is_signed);
}

int		AForm::getSignGrade() const
{
	return (this->_sign_grade);
}

int		AForm::getExecGrade() const
{
	return (this->_exec_grade);
}

std::string	AForm::getTarget() const
{
	return (this->_target);
}

void	AForm::beSigned(const Bureaucrat& signer)
{
	if (this->_sign_grade < signer.getGrade())
		throw tooLow;
	else
		this->_is_signed = true;
}

void	AForm::execute(const Bureaucrat& executer) const
{
	if (this->_is_signed == false)
		throw notSigned;
	else if (this->_exec_grade < executer.getGrade())
		throw tooLow;
	else
		this->action();
}
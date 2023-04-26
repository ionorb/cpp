/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:56:36 by codespace         #+#    #+#             */
/*   Updated: 2023/04/26 14:28:22 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
#include <iostream>
#include "GradeException.hpp"
#include "AForm.hpp"
#include "ASCIItree.hpp"

class ShrubberyCreationForm : public AForm
{
	// private:
	// 	std::string const	_name;
	// 	bool				_is_signed;
	// 	int const			_sign_grade;
	// 	int const			_exec_grade;
	// 	static const int	_max_grade = 1;
	// 	static const int	_min_grade = 150;
	// 	GradeTooHighException	tooHigh;
	// 	GradeTooLowException	tooLow;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm&	operator = (const ShrubberyCreationForm& copy);
		virtual void			action(void) const;
		// bool		getSignStatus() const;
		// int			getSignGrade() const;
		// int			getExecGrade() const;
		// void		beSigned(const Bureaucrat& signer);
};

#endif

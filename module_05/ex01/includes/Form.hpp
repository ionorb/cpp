/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:22:36 by codespace         #+#    #+#             */
/*   Updated: 2023/04/24 23:11:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
#include <iostream>
#include "GradeException.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_is_signed;
		int const			_sign_grade;
		int const			_exec_grade;
		static const int	_max_grade = 1;
		static const int	_min_grade = 150;
		GradeTooHighException	tooHigh;
		GradeTooLowException	tooLow;
	public:
		Form();
		Form(std::string name, int sign_grade, int exec_grade);
		virtual ~Form();
		Form(const Form& copy);
		Form&		operator = (const Form& copy);
		std::string	getName() const;
		bool		getSignStatus() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		void		beSigned(const Bureaucrat& signer);
};

std::ostream&	operator << (std::ostream& out, const Form& a);

#endif

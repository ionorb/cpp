/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:22:36 by codespace         #+#    #+#             */
/*   Updated: 2023/04/26 15:38:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
#include <iostream>
#include "GradeException.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_is_signed;
		int const			_sign_grade;
		int const			_exec_grade;
		static const int	_max_grade = 1;
		static const int	_min_grade = 150;
		std::string const	_target;
		GradeTooHighException	tooHigh;
		GradeTooLowException	tooLow;
		FormNotSigned			notSigned;
	public:
		AForm();
		AForm(std::string name, std::string target, int sign_grade, int exec_grade);
		virtual ~AForm();
		AForm(const AForm& copy);
		AForm&			operator = (const AForm& copy);
		std::string		getName() const;
		bool			getSignStatus() const;
		int				getSignGrade() const;
		int				getExecGrade() const;
		std::string		getTarget() const;
		void			beSigned(const Bureaucrat& signer);
		void			execute(Bureaucrat const & executor) const;
		virtual void	action(void) const = 0;
};

std::ostream&	operator << (std::ostream& out, const AForm& a);

#endif

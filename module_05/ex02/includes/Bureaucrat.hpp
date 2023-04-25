/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:10:39 by codespace         #+#    #+#             */
/*   Updated: 2023/04/25 09:36:40 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include <iostream>
#include "GradeException.hpp"
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;
		static const int	_max_grade = 1;
		static const int	_min_grade = 150;
		GradeTooHighException	tooHigh;
		GradeTooLowException	tooLow;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		virtual ~Bureaucrat();
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat&		operator = (const Bureaucrat& copy);
		void			upgrade();
		void			downgrade();
		std::string		getName() const;
		int				getGrade() const;
		void			setGrade(int grade);
		void			signForm(AForm& form) const;
};

std::ostream&	operator << (std::ostream& out, const Bureaucrat& a);

#endif

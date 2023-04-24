/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:10:39 by codespace         #+#    #+#             */
/*   Updated: 2023/04/24 21:19:18 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include <iostream>
#include "GradeException.hpp"

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
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat&		operator = (const Bureaucrat& copy);
		void			upgrade();
		void			downgrade();
		std::string		getName() const;
		int				getGrade() const;
		void			setGrade(int grade);
};

std::ostream&	operator << (std::ostream& out, const Bureaucrat& a);

#endif

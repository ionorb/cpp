/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeException.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:12:15 by codespace         #+#    #+#             */
/*   Updated: 2023/04/27 13:44:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADEEXCEPTION_HPP
# define GRADEEXCEPTION_HPP
#include <exception>

class GradeTooHighException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class GradeTooLowException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class FormNotSigned : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class InexistantForm : public std::exception
{
	public:
		virtual const char* what() const throw();
};


#endif

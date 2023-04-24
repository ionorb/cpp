/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeException.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:12:15 by codespace         #+#    #+#             */
/*   Updated: 2023/04/24 21:14:55 by codespace        ###   ########.fr       */
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

#endif

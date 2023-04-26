/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeException.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:12:43 by codespace         #+#    #+#             */
/*   Updated: 2023/04/26 14:34:10 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GradeException.hpp"

const char*	GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}

const char*	GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}

const char*	FormNotSigned::what() const throw()
{
	return ("Form Not Signed");
}
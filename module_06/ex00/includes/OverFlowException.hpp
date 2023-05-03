/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OverFlowException.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <myaccount@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:17:30 by myaccount         #+#    #+#             */
/*   Updated: 2023/05/03 14:23:29 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OVERFLOWEXCEPTION_HPP
# define OVERFLOWEXCEPTION_HPP
#include <exception>

class OverFlowException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

#endif

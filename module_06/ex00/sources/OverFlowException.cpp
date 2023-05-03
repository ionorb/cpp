/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OverFlowException.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <myaccount@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:17:29 by myaccount         #+#    #+#             */
/*   Updated: 2023/05/03 14:22:30 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OverFlowException.hpp"

const char*	OverFlowException::what() const throw()
{
	return ("Overflow");
}

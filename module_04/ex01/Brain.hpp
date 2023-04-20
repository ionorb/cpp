/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <myaccount@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:32:59 by myaccount         #+#    #+#             */
/*   Updated: 2023/04/19 19:21:53 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
#include <iostream>

class	Brain
{
	public:
		Brain();
		virtual ~Brain();
		Brain(const Brain& copy);
		Brain&	operator = (const Brain& copy);
	protected:
		std::string	ideas[100];
};

#endif

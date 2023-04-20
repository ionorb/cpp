/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <myaccount@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:32:59 by myaccount         #+#    #+#             */
/*   Updated: 2023/04/20 21:01:25 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
#include <iostream>

class	Brain
{
	public:
		Brain();
		~Brain();
		Brain(const Brain& copy);
		Brain&	operator = (const Brain& copy);
		std::string*	getIdeas(void);
		void			setIdeas(std::string idea);
	protected:
		std::string	ideas[100];
};

#endif

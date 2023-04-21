/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:32:59 by myaccount         #+#    #+#             */
/*   Updated: 2023/04/21 15:01:52 by codespace        ###   ########.fr       */
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
		Brain(std::string idea);
		Brain&	operator = (const Brain& copy);
		std::string*	getIdeas(void);
		void			setIdeas(std::string idea);
	protected:
		std::string	ideas[100];
};

#endif

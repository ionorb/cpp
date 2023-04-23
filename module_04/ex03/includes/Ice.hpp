/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:27:51 by codespace         #+#    #+#             */
/*   Updated: 2023/04/23 16:58:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
#include <iostream>
#include "Character.hpp"
#include "AMateria.hpp"

class Ice : public AMateria
{
	// protected:
	// 	std::string	type;
	public:
		Ice();
		Ice(std::string const & type);
		virtual ~Ice();
		Ice(const Ice& copy);
		Ice&	operator = (const Ice& copy);
		virtual Ice*	clone() const;
		virtual void	use(ICharacter& target);
};

#endif
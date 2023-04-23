/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:45:31 by codespace         #+#    #+#             */
/*   Updated: 2023/04/23 16:58:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
#include <iostream>
#include "Character.hpp"
#include "AMateria.hpp"

class Cure : public AMateria
{
	// protected:
	// 	std::string	type;
	public:
		Cure();
		Cure(std::string const & type);
		virtual ~Cure();
		Cure(const Cure& copy);
		Cure&	operator = (const Cure& copy);
		virtual Cure*	clone() const;
		virtual void	use(ICharacter& target);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:09:50 by codespace         #+#    #+#             */
/*   Updated: 2023/04/22 17:20:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
#include <iostream>

class AMateria
{
	protected:
		std::string	type;
	public:
		AMateria();
		virtual ~AMateria();
		AMateria(const AMateria& copy);
		AMateria&	operator = (const AMateria& copy);
		AMateria(std::string const & type);
		std::string const&	getType() const; //Returns the materia type
		virtual AMateria*	clone() const = 0;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 13:29:20 by codespace         #+#    #+#             */
/*   Updated: 2023/04/23 15:52:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
#include <iostream>
#include "Character.hpp"
#include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& copy);
		MateriaSource&	MateriaSource::operator = (const MateriaSource& copy);
		virtual ~MateriaSource();
		virtual void learnMateria(AMateria* ptr);
		virtual AMateria* createMateria(std::string const & type);
	private:
		AMateria	*learned[4];
		// int			num_learned;
};

#endif
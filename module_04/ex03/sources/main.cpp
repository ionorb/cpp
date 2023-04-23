/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:53:37 by codespace         #+#    #+#             */
/*   Updated: 2023/04/23 19:49:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "AMateria.hpp"
// #include "Cure.hpp"
// #include "Ice.hpp"
// #include "Character.hpp"
// #include "MateriaSource.hpp"

// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice("cold"));
// 	src->learnMateria(new Cure("hot"));

// 	ICharacter* me = new Character("me");

// 	AMateria* tmp;
// 	tmp = src->createMateria("cold");
// 	me->equip(tmp);
// 	tmp = src->createMateria("hot");
// 	me->equip(tmp);

// 	ICharacter* bob = new Character("bob");
	
// 	me->use(0, *bob);
// 	me->use(1, *bob);

// 	delete bob;
// 	delete me;
// 	delete src;

// 	return 0;
// }

#include <iostream>
#include <iomanip>
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"

void	main_print_banner(std::string title);

int	main(void)
{
	std::clog.setstate(std::ios_base::failbit);

	main_print_banner("Subject Test");
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice()); 
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		std::cout << std::endl;

		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		std::cout << std::endl;

		me->use(0, *bob);
		me->use(1, *bob);
		std::cout << std::endl;
	
		delete bob;
		delete me;
		delete src;
	}

	std::clog.clear();
	{
		main_print_banner("Constructors");
		// IMateriaSource	imaterial;
		// AMateria		amateria;

		Ice		i;
		std::cout << std::endl;
		Cure	c;
		std::cout << std::endl;
		Character	ch("Pepito");
		std::cout << std::endl;
		MateriaSource	ms;
		std::cout << std::endl;
		
		main_print_banner("Learn materia");
		ms.learnMateria(NULL);
		ms.learnMateria(new Ice()); 
		ms.learnMateria(new Cure());
		ms.learnMateria(new Ice()); 
		ms.learnMateria(new Cure());
		ms.learnMateria(new Ice()); 
		ms.learnMateria(new Cure());
		

		std::cout << std::endl;
		main_print_banner("Equip materia");
		ch.equip(ms.createMateria("ice"));
		ch.equip(ms.createMateria("cure"));
		ch.equip(ms.createMateria("ice"));
		ch.equip(ms.createMateria("cure"));
		ch.equip(ms.createMateria("ice"));
		ch.equip(ms.createMateria("cure"));


		ch.equip(ms.createMateria("make popkorn"));
		ch.equip(NULL);
		std::cout << std::endl;

		main_print_banner("Constructors copy");
		Ice		i2(i);
		std::cout << std::endl;
		Cure	c2(c);
		std::cout << std::endl;
		Character	ch2(ch);
		std::cout << std::endl;
		MateriaSource	ms2(ms);
		std::cout << std::endl;

		main_print_banner("Print inventory constructor copies");
		// ms2.print();	
		std::cout << std::endl;
		// ch2.print();
		std::cout << std::endl;

		main_print_banner("Copy operators");
		Ice		i3;
		std::cout << std::endl;
		Cure	c3;
		std::cout << std::endl;
		Character	ch3("Juanito");
		std::cout << std::endl;
		MateriaSource	ms3;

		i3 = i2;
		c3 = c2;
		ch3 = ch2;
		ms3 = ms2;

		std::cout << std::endl;

		main_print_banner("Print inventory copy operator");
		// ms3.print();	
		std::cout << std::endl;
		// ch3.print();
		std::cout << std::endl;

		main_print_banner("unequip");
		ch3.unequip(-800);
		ch3.unequip(0);
		ch3.unequip(0);
		ch3.unequip(3);
		ch3.unequip(500);
		std::cout << std::endl;
		main_print_banner("Print inventory after unequip");
		// ch3.print();	
		std::cout << std::endl;
	}
	return (0);
}


void	main_print_banner(std::string title)
{	
	std::cout	<<	std::endl;
	std::cout	<<	std::setfill('*') << std::setw(title.size()) << "" << std::endl;
	std::cout	<<	title	<<	std::endl;
	std::cout	<<	std::setfill('*') << std::setw(title.size()) << "" << std::endl;
	std::cout	<<	std::endl;

}

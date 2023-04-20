/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <myaccount@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:13:45 by myaccount         #+#    #+#             */
/*   Updated: 2023/04/20 22:40:10 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\n--------TESTS--------\n";
	std::cout << "\nTEST FROM SUBJECT:\n\n";
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j; //should not create a leak
		delete i;
	}
	std::cout << "\n----------------\n";
	std::cout << "\nANIMAL ARRAY:\n\n";
	{
		Animal	*array[4];
		
		for (int i = 0; i < 2; i++)
			array[i] = new Cat();
		for (int i = 2; i < 4; i++)
			array[i] = new Dog();
		for (int i = 0; i < 4; i++)
			delete array[i];
	}
	std::cout << "\n----------------\n";
	std::cout << "\nDEEP COPY TEST:\n\n";
	{
		Cat		a;
		Cat		b;
		Cat		c;

		std::cout << "\nA brain:\n";
		a.setBrain("boop");
		a.printBrain();
		std::cout << "\nB brain:\n";
		b = a;
		b.printBrain();
		std::cout << "\nC brain:\n";
		c = Cat(a);
		// c.printBrain();
		std::cout <<"hello\n";
	}
	std::cout << "\n----------------\n";
	std::cout << "\nGOOD ANIMALS:\n\n";
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
	}
	std::cout << "\n----------------\n";
	std::cout << "\nWRONG ANIMALS:\n\n";
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();

		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		meta->makeSound();
		delete meta;
		delete i;
	}
	std::cout << "\n----------------\n";
	return 0;
}
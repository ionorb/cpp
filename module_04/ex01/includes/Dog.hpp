/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:36:47 by myaccount         #+#    #+#             */
/*   Updated: 2023/04/21 17:16:15 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		virtual ~Dog(void);
		Dog(const Dog& other);
		Dog&	operator = (const Dog& other);
		void	makeSound(void) const;
		void	printBrain(void);
		void	setBrain(std::string idea);
	private:
		Brain*	brain;
};

#endif

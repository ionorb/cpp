/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <myaccount@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:36:47 by myaccount         #+#    #+#             */
/*   Updated: 2023/04/20 21:02:30 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		~Cat(void);
		Cat(const Cat& other);
		Cat&	operator = (const Cat& other);
		void	makeSound(void) const;
		void	printBrain(void);
		void	setBrain(std::string idea);
	private:
		Brain*	brain;
};

#endif
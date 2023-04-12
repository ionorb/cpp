/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <yoel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:30:20 by yoel              #+#    #+#             */
/*   Updated: 2023/04/12 15:44:20 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>
#include <iostream>

class	Zombie {


	public:
	
		Zombie(std::string new_name);
		~Zombie(void);
		void	announce(void);


	private:

		std::string	name;


};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:27:32 by yridgway          #+#    #+#             */
/*   Updated: 2023/04/17 17:04:47 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap& frag);
		~FragTrap();
		FragTrap&	operator = (const FragTrap& frag);
		void		attack(const std::string& target);
		void		highFivesGuys(void);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <myaccount@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:36:47 by myaccount         #+#    #+#             */
/*   Updated: 2023/04/19 18:16:46 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONFCAT_HPP
# define WRONFCAT_HPP
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		virtual ~WrongCat(void);
		WrongCat(const WrongCat& other);
		WrongCat&	operator = (const WrongCat& other);
		void		makeSound(void) const;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <yoel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:28:01 by yridgway          #+#    #+#             */
/*   Updated: 2023/04/14 00:53:32 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called\n";
	fixed_num = 0;
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called\n";
	fixed_num = fixed.fixed_num;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	fixed_num = fixed.fixed_num;
	std::cout << "Copy assignment operator called\n";
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
	fixed_num = 0;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (fixed_num);
}

void	Fixed::setRawBits(int const raw)
{
	fixed_num = raw;
}

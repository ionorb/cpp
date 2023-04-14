/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:28:01 by yridgway          #+#    #+#             */
/*   Updated: 2023/04/14 17:22:01 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called\n";
	this->fixed_num = 0;
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called\n";
	*this = fixed;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called\n";
	this->fixed_num = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->fixed_num);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	this->fixed_num = raw;
}

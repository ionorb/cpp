/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:28:01 by yridgway          #+#    #+#             */
/*   Updated: 2023/04/14 20:17:24 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called\n";
	this->rawbits = 0;
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called\n";
	*this = fixed;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called\n";
	this->rawbits = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

int		Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called\n";
	return (this->rawbits);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called\n";
	this->rawbits = raw;
}

Fixed::Fixed(const int integer)
{
	this->rawbits = integer << this->fbits;
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float floating)
{
	std::cout << "Float constructor called\n";
	this->rawbits = (int)roundf(floating * (1 << this->fbits));
}
		
float	Fixed::toFloat(void) const
{
	return ((float)this->rawbits / (float)(1 << this->fbits));
}

int		Fixed::toInt(void) const
{
	return (this->rawbits >> 8);
}

std::ostream&	operator << (std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}

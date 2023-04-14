/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:28:01 by yridgway          #+#    #+#             */
/*   Updated: 2023/04/14 22:25:43 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

//CONSTRUCTORS
Fixed::Fixed(void)
{
	// std::cout << "Default constructor called\n";
	this->rawbits = 0;
}

Fixed::Fixed(const Fixed& fixed)
{
	// std::cout << "Copy constructor called\n";
	*this = fixed;
}

Fixed::Fixed(const int integer)
{
	this->rawbits = integer << this->fbits;
	// std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float floating)
{
	// std::cout << "Float constructor called\n";
	this->rawbits = (int)roundf(floating * (1 << this->fbits));
	// std::cout << "rawbits are: " << this->rawbits << "\n";
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	// std::cout << "Copy assignment operator called\n";
	this->rawbits = fixed.getRawBits();
	return *this;
}


//DESTRUCTOR
Fixed::~Fixed(void)
{
	// std::cout << "Destructor called\n";
}


//MEATHODS
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



//CONVERSIONS
float	Fixed::toFloat(void) const
{
	return ((float)this->rawbits / (float)(1 << this->fbits));
}

int		Fixed::toInt(void) const
{
	return (this->rawbits >> 8);
}


//COUT STREAM
std::ostream&	operator << (std::ostream& out, const Fixed& fixed)
{
	// std::cout << fixed.getRawBits() << "\n";
	// std::cout << fixed.toFloat() << "\n";
	out << fixed.toFloat();
	return (out);
}


//COMPARISONS
bool			operator > (const Fixed& left, const Fixed& right)
{
	return (left.getRawBits() > right.getRawBits());
}

bool			operator >= (const Fixed& left, const Fixed& right)
{
	return (left.getRawBits() >= right.getRawBits());
}

bool			operator < (const Fixed& left, const Fixed& right)
{
	return (left.getRawBits() < right.getRawBits());
}

bool			operator <= (const Fixed& left, const Fixed& right)
{
	return (left.getRawBits() <= right.getRawBits());
}

bool			operator == (const Fixed& left, const Fixed& right)
{
	return (left.getRawBits() == right.getRawBits());
}

bool			operator != (const Fixed& left, const Fixed& right)
{
	return (left.getRawBits() != right.getRawBits());
}


//ARITHMETIC
Fixed			operator + (const Fixed& left, const Fixed& right)
{
	Fixed	sum;
	
	sum.setRawBits(left.getRawBits() + right.getRawBits());
	return (sum);
}

Fixed			operator - (const Fixed& left, const Fixed& right)
{
	Fixed	sum;
	
	sum.setRawBits(left.getRawBits() - right.getRawBits());
	return (sum);
	
}

Fixed			operator * (const Fixed& left, const Fixed& right)
{
	Fixed	product;

	product.setRawBits(left.getRawBits() * right.getRawBits());
	return (product);
}

Fixed			operator / (const Fixed& left, const Fixed& right)
{
	Fixed	product;

	product.setRawBits(left.getRawBits() / right.getRawBits());
	return (product);
	
}


//MAX & MIN
Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f2);
	return (f1);
}

const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f2);
	return (f1);
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}

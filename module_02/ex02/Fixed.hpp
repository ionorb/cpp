/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:28:05 by yridgway          #+#    #+#             */
/*   Updated: 2023/04/14 22:22:12 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class	Fixed
{
	private:
		int					rawbits;
		static const int	fbits = 8;
	
	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed(const int integer);
		Fixed(const float floating);
		Fixed&	operator = (const Fixed& fixed);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		static Fixed&			min(Fixed& f1, Fixed& f2);
		static const Fixed&		min(const Fixed& f1, const Fixed& f2);
		static Fixed&			max(Fixed& f1, Fixed& f2);
		static const Fixed&		max(const Fixed& f1, const Fixed& f2);
};

std::ostream&	operator << (std::ostream& out, const Fixed& fixed);

bool			operator > (const Fixed& left, const Fixed& right);
bool			operator >= (const Fixed& left, const Fixed& right);
bool			operator < (const Fixed& left, const Fixed& right);
bool			operator <= (const Fixed& left, const Fixed& right);
bool			operator == (const Fixed& left, const Fixed& right);
bool			operator != (const Fixed& left, const Fixed& right);

Fixed			operator + (const Fixed& left, const Fixed& right);
Fixed			operator - (const Fixed& left, const Fixed& right);
Fixed			operator * (const Fixed& left, const Fixed& right);
Fixed			operator / (const Fixed& left, const Fixed& right);

#endif

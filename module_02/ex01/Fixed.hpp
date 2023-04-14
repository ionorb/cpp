/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:28:05 by yridgway          #+#    #+#             */
/*   Updated: 2023/04/14 20:12:32 by yridgway         ###   ########.fr       */
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
};

std::ostream&	operator << (std::ostream& out, const Fixed& fixed);

#endif

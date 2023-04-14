/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:27:17 by yridgway          #+#    #+#             */
/*   Updated: 2023/04/14 22:26:10 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed big(69.699f);;
	Fixed small(42.429f);
	Fixed sum;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;

	// std::cout << b << std::endl;

	// std::cout << Fixed::max( a, b ) << std::endl;
	// if (big > small)
	// 	std::cout << "big is bigger than small\n";
	// if (small < big)
	// 	std::cout << "small is smaller than big\n";
	// if (big >= small)
	// 	std::cout << "big is bigger or equal to small\n";
	// if (small <= big)
	// 	std::cout << "small is less than or equal to big\n";
	// if (small == big)
	// 	std::cout << "small is equal to big\n";
	// if (small != big)
	// 	std::cout << "small does not equal big\n";
	sum = small + big;
	std:: cout << big << " + " << small << " = " << sum << std::endl;
	sum = small - big;
	std:: cout << small << " - " << big << " = " << sum << std::endl;
	sum = small * big;
	std:: cout << big << " * " << small << " = " << sum << std::endl;
	sum = small / big;
	std:: cout << big << " / " << small << " = " << sum << std::endl;
	std:: cout << big.max(big, small) << "\n";
	std:: cout << big.max(small, big) << "\n";
	std:: cout << small.max(big, small) << "\n";
	std:: cout << small.max(small, big) << "\n";
	// std::cout << small.getRawBits();
	// std::cout << fixed.toFloat();
	return (0);
}

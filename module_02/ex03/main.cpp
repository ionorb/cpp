/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:27:17 by yridgway          #+#    #+#             */
/*   Updated: 2023/04/15 21:21:59 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// int main( void )
// {
// 	Fixed big(69.699f);;
// 	Fixed small(42.429f);
// 	Fixed sum;
// 	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

// 	// std::cout << a << std::endl;
// 	// std::cout << ++a << std::endl;
// 	// std::cout << a << std::endl;
// 	// std::cout << a++ << std::endl;
// 	// std::cout << a << std::endl;

// 	// std::cout << b << std::endl;

// 	// std::cout << Fixed::max( a, b ) << std::endl;
// 	sum = small + big;
// 	std:: cout << big << " + " << small << " = " << sum << std::endl;
// 	sum = small - big;
// 	std:: cout << small << " - " << big << " = " << sum << std::endl;
// 	sum = small * big;
// 	std:: cout << big << " * " << small << " = " << sum << std::endl;
// 	sum = small / big;
// 	std:: cout << big << " / " << small << " = " << sum << std::endl;
// 	std:: cout << big.max(big, small) << "\n";
// 	std:: cout << big.max(small, big) << "\n";
// 	std:: cout << small.max(big, small) << "\n";
// 	std:: cout << small.max(small, big) << "\n";
// 	return (0);
// }

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "a: " << a << std::endl;
	std::cout << "a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a: " << a++ << std::endl << std::endl;
	std::cout << "a: " << a << std::endl;

	std::cout << "b: " << b << std::endl;
	std::cout << "max: " << Fixed::max( a, b ) << std::endl;
	std::cout << "min: " << Fixed::min( a, b ) << std::endl;
	return 0;
}
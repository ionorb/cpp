/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stupid.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:27:17 by yridgway          #+#    #+#             */
/*   Updated: 2023/04/16 19:28:37 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) 
{
	Point	a(1, 3);
	Point	b(4, 6);
	Point	c(6, 2);
	Point	p[3] = {Point(1, 3), Point(4, 6), Point(6, 2)};

	for (int i = 0; i < 3; i++)
	{
		std::cout << "Point: (" << p[i].getx() << ", " << p[i].gety() << ")";
		if (bsp(a, b, c, p[i]))
			std::cout << " is in the triangle\n";
		else
			std::cout << " is NOT in the triangle\n";
	}
	return 0;
}

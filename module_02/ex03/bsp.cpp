/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:55:09 by yridgway          #+#    #+#             */
/*   Updated: 2023/04/16 17:05:24 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

// Fixed	sign(Point p, Point p1, Point p2)
// {
// 	return ((p.getx() - p2.getx()) * (p1.gety() - p2.gety())
// 			- (p1.getx() - p2.getx()) * (p.gety() - p2.gety()));
// }

// bool	bsp( Point const a, Point const b, Point const c, Point const point)
// {
// 	Fixed	s1, s2, s3;
// 	bool	negative, positive;
	
// 	s1 = sign(point, a, b);
// 	s2 = sign(point, b, c);
// 	s3 = sign(point, c, a);

// 	std::cout << s1 << std::endl << s2 << std::endl << s3 << std::endl;
// 	if (!s1.getRawBits() || !s2.getRawBits() || !s3.getRawBits())
// 		return (false);
// 	negative = (s1 < 0) || (s2 < 0) || (s3 < 0);
// 	positive = (s1 > 0) || (s2 > 0) || (s3 > 0);
// 	return (!(positive && negative));
// }

bool	isLeft(Point a, Point b, Point p)
{
	return ((b.getx() - a.getx()) * (p.gety() - a.gety()) - (b.gety() - a.gety()) * (p.getx() - a.getx())) >= 0;
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	return !(isLeft(a, b, point) || isLeft(b, c, point) || isLeft(c, a, point));
}

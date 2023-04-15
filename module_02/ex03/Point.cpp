/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:56:12 by yridgway          #+#    #+#             */
/*   Updated: 2023/04/16 00:42:55 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) //default constructor
{
	std::cout << "point constructor called\n";
}

Point::Point(const float x, const float y) : x(x), y(y) //overloaded constructor
{
	std::cout << "overloaded point constructor called\n";
}

Point::Point(const Point& p) //copy constructor
{
	*this = p;
}

Point&	Point::operator = (const Point& p) //copy assignment overload
{
	// this->~Point();
	new(this) Point(p);
	return (*this);
}

Point::~Point(void) //default destructor
{
	std::cout << "point destructor called\n";
}

Fixed	Point::getx(void)
{
	return (this->x);
}

Fixed	Point::gety(void)
{
	return (this->y);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:26:45 by yridgway          #+#    #+#             */
/*   Updated: 2023/04/16 18:10:40 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;

	public:
		Point(void);
		Point(const float x, const float y);
		// Point(const Fixed x, const Fixed y);
		Point(const Point& p);
		Point&	operator = (const Point& p);
		~Point(void);
		Fixed	getx();
		Fixed	gety();
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);

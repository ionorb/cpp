/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:27:17 by yridgway          #+#    #+#             */
/*   Updated: 2023/04/16 19:27:20 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <fstream>
#include <sstream>
// #include <random>

typedef struct s_rgb
{
	unsigned char x;
	unsigned char y;
	unsigned char z;
}	t_rgb;

typedef struct s_vec
{
	double x;
	double y;
}	t_vec;

void	draw_line(t_vec from, t_vec to, t_rgb **image, t_rgb color)
{
	float	dx, dy, step;
	// Point	current(from.getx().toFloat(), from.gety().toFloat());
	t_vec	current = {from.x, from.y};
	int		i;
	
	(void)image;
	(void)color;
	dx = (to.x - from.x);
	dy = (to.y - from.y);
	if (fabs(dx) >= fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	dx = dx / step;
	dy = dy / step;
	i = -1;
	// image[1][1] = color;
	while (++i < step)
	{
		image[(int)(current.y)][(int)(current.x)] = color;
		current.x = current.x + dx;
		current.y = current.y + dy;
	}
}

void	saveppm(int x, int y, t_vec triangle[3], Point tri[3])
{
	t_rgb	rgb;
	t_rgb	red = {255, 0, 0};
	t_rgb	blue = {0, 0, 255};
	t_rgb	white = {255, 255, 255};
	t_rgb	black = {0, 0, 0};
	t_rgb	**image;;

	image = new t_rgb* [y];
	for (int i = 0; i < y; ++i)
		image[i] = new t_rgb[x];
	for(int i = 0; i < y; i++)
		for(int j = 0; j < x; j++)
			image[i][j] = white;
	std::cout << triangle[0].x << std::endl;
	std::cout << triangle[0].y << std::endl;
	image[(int)(triangle[0].y)][(int)(triangle[0].x)] = red;
	image[(int)(triangle[1].y)][(int)(triangle[1].x)] = blue;
	image[(int)(triangle[2].y)][(int)(triangle[2].x)] = black;
	draw_line(triangle[0], triangle[1], image, black);
	draw_line(triangle[1], triangle[2], image, black);
	draw_line(triangle[2], triangle[0], image, black);
	for (int i = 0; i < 100000; i++)
	{
		int	random_x = rand() % 999;
		int	random_y = rand() % 999;
		Point p((float)random_x / 100, (float)random_y / 100);
		if (bsp(tri[0], tri[1], tri[2], p))
			image[random_y][random_x] = blue;
		else
			image[random_y][random_x] = red;
	}
	std::ofstream output("outfile.ppm", std::ios::binary);
	if (output.is_open())
	{
		output << "P6\n" << x << std::endl << y << std::endl << 255 << std::endl;
		for(int i = y - 1; i >= 0; i--)
			for(int j = 0; j < x; j++)
				output.write((char*)&image[i][j], sizeof(rgb));
	}
	for (int i = 0; i < y; ++i)
		delete[] image[i];
	delete[] image;
}

int main( void ) 
{
	Point	a(1, 3);
	Point	b(4, 6);
	Point	c(6, 2);
	Point	p[3] = {Point(1, 3), Point(4, 6), Point(6, 2)};
	t_vec	triangle[3];
	for (int i = 0; i < 3; i++)
	{
		std::cout << "Point: (" << p[i].getx() << ", " << p[i].gety() << ")";
		triangle[i] = (t_vec){(p[i].getx() * 100).toInt(), (p[i].gety() * 100).toInt()};
		if (bsp(a, b, c, p[i]))
			std::cout << " is in the triangle\n";
		else
			std::cout << " is NOT in the triangle\n";
	}
	saveppm(1000, 1000, triangle, p);
	return 0;
}
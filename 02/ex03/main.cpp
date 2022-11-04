/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:34:54 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/04 01:27:01 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cassert>
#include "Point.hpp"

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define RESET "\033[0m"
void print_matrix(int matrix[20][20], bool point_inside)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			switch (matrix[i][j])
			{
				case 0:
					std::cout << " ";
					break;
				case 1:
					std::cout << "a";
					break;
				case 2:
					std::cout << "b";
					break;
				case 3:
					std::cout << "c";
					break;
				case 9:
					if (point_inside)
						std::cout << GREEN << "X" << RESET;
					else
						std::cout << RED << "X" << RESET;
					break;
				default:
					break;
			}
		}
		std::cout << std::endl;
	}
}

void render_triangle(Point &a, Point &b, Point &c, Point &p)
{
	// check if everything can fit in a 20x20 matrix
	int ax = 10 + a.getX().toInt();
	int ay = 10 - a.getY().toInt();
	int bx = 10 + b.getX().toInt();
	int by = 10 - b.getY().toInt();
	int cx = 10 + c.getX().toInt();
	int cy = 10 - c.getY().toInt();
	int px = 10 + p.getX().toInt();
	int py = 10 - p.getY().toInt();
	
	if (ax > 19 || ay > 19 || bx > 19 || by > 19 || cx > 19 || cy > 19 || px > 19 || py > 19)
	{
		std::cout << RED << "Point(s) out of range. Unable to render the triangle." << RESET << std::endl;
		return;
	}

	int orthonormal_plane[20][20] = {0};
	orthonormal_plane[ay][ax] = 1;
	orthonormal_plane[by][bx] = 2;
	orthonormal_plane[cy][cx] = 3;
	orthonormal_plane[py][px] = 9;
	print_matrix(orthonormal_plane, bsp(a, b, c, p));
}

int main( void ) {
	Point a = Point(3.0f, 2.0f);
	Point b = Point(5.0f, 0.0f);
	Point c = Point(0.0f, 0.0f);
	Point p = Point(3.0f, 1.0f);

	render_triangle(a, b, c, p);
	
	if (bsp(a, b, c, p) == true)
		std::cout << GREEN << "Point is inside the triangle" << RESET << std::endl;
	else
		std::cout << RED << "Point is outside the triangle" << RESET << std::endl;
}

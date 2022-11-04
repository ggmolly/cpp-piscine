/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:08:22 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/04 01:26:51 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void): _x(Fixed(0)), _y(Fixed(0))
{

}

Point::Point(Fixed const &x, Fixed const &y): _x(x), _y(y)
{

}

Point::~Point()
{

}

Fixed const &Point::getX(void) const
{
	return _x;
}

Fixed const &Point::getY(void) const
{
	return _y;
}

Point::Point(const Point &point): _x(point.getX()), _y(point.getY())
{

}

Point& Point::operator= (const Point& point)
{
	(void)point;
	std::cout << "Unable to copy Point as its members are const" << std::endl;
	return *this;
}

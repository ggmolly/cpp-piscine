/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:07:32 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/04 01:01:41 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;
	public:
		Point(void);
		Point(const Point &);
		Point(Fixed const &x, Fixed const &y);
		~Point();
		Point& operator= (const Point& point);
		Fixed const &getX(void) const;
		Fixed const &getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
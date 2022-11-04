/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:22:29 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/03 23:48:23 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed c1 = (point.getX() - a.getX()) * (b.getY() - a.getY()) - (b.getX() - a.getX()) * (point.getY() - a.getY());
	Fixed c2 = (point.getX() - b.getX()) * (c.getY() - b.getY()) - (c.getX() - b.getX()) * (point.getY() - b.getY());
	Fixed c3 = (point.getX() - c.getX()) * (a.getY() - c.getY()) - (a.getX() - c.getX()) * (point.getY() - c.getY());
	if (c1 * c2 > 0 && c2 * c3 > 0)
		return true;
	return false;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:34:50 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/03 15:33:05 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_fixed_point = 0;
}

Fixed::~Fixed()
{

}

Fixed::Fixed(Fixed &f)
{
	if (this == &f)
		return ;
	*this = f;
}

Fixed& Fixed::operator= (const Fixed& fixed)
{
	this->_fixed_point = fixed.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return this->_fixed_point;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixed_point = raw;
}

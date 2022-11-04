/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:34:50 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/03 22:40:19 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixed_point = 0;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this == &f)
		return ;
	*this = f;
}

Fixed::Fixed(int const n)
{
	std::cout << "int constructor called" << std::endl;
	this->_fixed_point = n << this->_bits;
}

Fixed::Fixed(float const n)
{
	std::cout << "float constructor called" << std::endl;
	this->_fixed_point = roundf(n * (1 << this->_bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator= (const Fixed& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed_point = fixed._fixed_point;
	this->setRawBits(fixed.getRawBits());
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

float Fixed::toFloat(void) const
{
	return (this->_fixed_point / (float)(1 << this->_bits));
}

int Fixed::toInt(void) const
{
	return (this->_fixed_point >> this->_bits);
}

std::ostream& operator<<(std::ostream & os, Fixed const & fixed)
{
	os << fixed.toFloat();
	return (os);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:34:50 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/03 23:03:48 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_fixed_point = 0;
}

Fixed::Fixed(const Fixed &f)
{
	if (this == &f)
		return ;
	*this = f;
}

Fixed::Fixed(int const n)
{
	this->_fixed_point = n << this->_bits;
}

Fixed::Fixed(float const n)
{
	this->_fixed_point = roundf(n * (1 << this->_bits));
}

Fixed::~Fixed()
{
}

Fixed& Fixed::operator= (const Fixed& fixed)
{
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
	return (this->getRawBits() / (float)(1 << this->_bits));
}

int Fixed::toInt(void) const
{
	return (this->getRawBits() >> this->_bits);
}

std::ostream& operator<<(std::ostream & os, Fixed const & fixed)
{
	os << fixed.toFloat();
	return (os);
}

// === Comparaison operators (>, <, <=, >=, ==, !=) === //
bool Fixed::operator>(const Fixed& fixed) const
{
	return (this->getRawBits() > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed& fixed) const
{
	return (this->getRawBits() < fixed.getRawBits());
}

bool Fixed::operator==(const Fixed& fixed) const
{
	return (this->getRawBits() == fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed& fixed) const
{
	return (!(*this < fixed));
}

bool Fixed::operator<=(const Fixed& fixed) const
{
	return (!(*this > fixed));
}


bool Fixed::operator!=(const Fixed& fixed) const
{
	return (!(*this == fixed));
}

// === Arithmetic operators (+, -, *, /) === //

Fixed Fixed::operator+(const Fixed& fixed) const
{
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator-(const Fixed& fixed) const
{
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator*(const Fixed& fixed) const
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed& fixed) const
{
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

// === Increment operators (++, --) === //

Fixed& Fixed::operator++()
{
	this->_fixed_point++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed& Fixed::operator--()
{
	this->_fixed_point--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

// === Min and Max === //

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	return (f1 < f2 ? f1 : f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	return (f1 < f2 ? f1 : f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	return (f1 > f2 ? f1 : f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	return (f1 > f2 ? f1 : f2);
}

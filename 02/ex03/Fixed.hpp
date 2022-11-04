/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:34:52 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/03 23:11:21 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int 			 _fixed_point;
		static const int _bits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &);
		Fixed(int const);
		Fixed(float const);
		~Fixed();
		Fixed& operator= (const Fixed& fixed);
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
		static Fixed		&min(Fixed &, Fixed &);
		static const Fixed	&min(const Fixed &, const Fixed &);
		static Fixed		&max(Fixed &, Fixed &);
		static const Fixed	&max(const Fixed &, const Fixed &);

		// Comparaison operators (>, <, <=, >=, ==, !=)
		bool operator>(const Fixed& fixed) const;
		bool operator<(const Fixed& fixed) const;
		bool operator>=(const Fixed& fixed) const;
		bool operator<=(const Fixed& fixed) const;
		bool operator==(const Fixed& fixed) const;
		bool operator!=(const Fixed& fixed) const;

		// Arithmetic operators (+, -, *, /)
		Fixed operator+(const Fixed& fixed) const;
		Fixed operator-(const Fixed& fixed) const;
		Fixed operator*(const Fixed& fixed) const;
		Fixed operator/(const Fixed& fixed) const;

		// Increment and decrement operators (++, --)
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);
};

std::ostream& operator<<(std::ostream&, const Fixed& a);
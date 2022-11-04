/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:34:52 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/03 23:11:18 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Fixed
{
	private:
		int 			 _fixed_point;
		static const int _bits = 8;
	public:
		Fixed(void);
		Fixed(Fixed &);
		~Fixed();
		Fixed& operator= (const Fixed& fixed);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};
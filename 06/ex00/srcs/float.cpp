/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:47:25 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/16 14:49:04 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

void displayFloat(double d)
{
	float f = static_cast<float>(d);
	float number = 0.0f;
	float decimals = modff(f, &number);
	std::cout << "float: " << f
		<< (decimals == 0 && (number == NAN || number != INFINITY) && (f > -1000000 && f < 1000000) ? ".0f" : "f")
		<< std::endl;
}
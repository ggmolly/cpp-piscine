/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:50:02 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/16 14:50:19 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

void displayChar(double d)
{
	std::cout << "char: ";
	if (d <= CHAR_MAX && d >= CHAR_MIN)
	{
		char c = static_cast<char>(d);
		std::cout << (isprint(c) ? std::string(1, c) : "not-printable") << std::endl;
	}
	else
		std::cout << "error" << std::endl;
}
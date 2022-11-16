/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:50:31 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/16 14:51:25 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

void displayInt(double d)
{
	std::cout << "int: ";
	if (d <= INT_MAX && d >= INT_MIN)
		std::cout << static_cast<int>(d) << std::endl;
	else
		std::cout << "error" << std::endl;
}

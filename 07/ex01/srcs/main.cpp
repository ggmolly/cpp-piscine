/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:19:59 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/17 22:13:26 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	std::cout << "========== PRINT ==========" << std::endl;
	{
		std::string array[4] = {
			"Hello",
			"World",
			"!",
			"This is a test."
		};
		iter(array, 4, print);
	}
	std::cout << "========== SQUARE ==========" << std::endl;
	{
		int array[4] = {
			2,
			4,
			6,
			8
		};
		iter(array, 4, squarePrint);
	}
	return (0);
}

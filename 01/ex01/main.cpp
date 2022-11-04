/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:59:39 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/04 11:51:20 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	smallHorde()
{
	std::cout << RED << ">>> Creating a small horde of 3 zombies <<<" << RESET << std::endl;
	Zombie *zombie = zombieHorde(3, "SmallHorde");
	for (int i = 0; i < 3; i++) {
		zombie[i].announce();
	}
	delete [] zombie;
}

void	bigHorde()
{
	std::cout << RED << ">>> Creating a big horde of 10 zombies <<<" << RESET << std::endl;
	Zombie *zombie = zombieHorde(10, "BigHorde");
	for (int i = 0; i < 10; i++) {
		zombie[i].announce();
	}
	delete [] zombie;
}

void emptyHorde()
{
	std::cout << RED << ">>> Creating a horde of size 0 <<<" << RESET << std::endl;
	Zombie *zombie = zombieHorde(0, "EmptyHorde");
	if (zombie == NULL)
		std::cout << "Horde is empty." << std::endl;
}

void negativeHorde()
{
	std::cout << RED << ">>> Creating a horde of size -10 <<<" << RESET << std::endl;
	Zombie *zombie = zombieHorde(-10, "NegativeHorde");
	if (zombie == NULL)
		std::cout << "Horde is empty." << std::endl;
}

int main() {
	smallHorde();
	bigHorde();
	emptyHorde();
	negativeHorde();
	return (0);
}
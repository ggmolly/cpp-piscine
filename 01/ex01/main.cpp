/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:59:39 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/31 21:42:43 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main() {
	std::cout << RED << "Creating a small horde of 3 zombies..." << RESET << std::endl;
	Zombie *zombie = zombieHorde(3, "SmallHorde");
	for (int i = 0; i < 3; i++) {
		zombie[i].announce();
	}
	delete [] zombie;

	std::cout << RED << "Creating a big horde of 10 zombies..." << RESET << std::endl;
	zombie = zombieHorde(10, "BigHorde");
	for (int i = 0; i < 10; i++) {
		zombie[i].announce();
	}
	delete [] zombie;

	return (0);
}
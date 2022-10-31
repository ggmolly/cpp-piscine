/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:59:39 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/31 19:55:37 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main() {
	Zombie *foo = newZombie("Foo");
	foo->announce();

	randomChump("Bar");

	delete(foo);
	return (0);
}
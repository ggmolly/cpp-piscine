/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:10:16 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/09 14:56:38 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	{
		ScavTrap st("Alice");
		ClapTrap ct("Bob");
		st.guardGate();
		st.attack("Bob");
		ct.takeDamage(20);
		ct.attack("Alice");
	}
	{
		ScavTrap st("Alice");
		for (size_t i = 0; i < 50; i++)
		{
			st.beRepaired(1);
		}
		st.attack("Someone");
	}
	{
		ScavTrap st("Alice");
		st.takeDamage(25);
		st.takeDamage(25);
		st.attack("Someone");
		st.takeDamage(50);
		st.attack("Someone");
	}
}
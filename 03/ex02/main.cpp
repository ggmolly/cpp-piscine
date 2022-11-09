/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:10:16 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/09 14:28:21 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap st("Test ScavTrap");
	FragTrap ft("Test FragTrap");
	st.guardGate();
	st.attack("Test FragTrap");
	ft.takeDamage(20);
	ft.attack("Test ScavTrap");
	st.takeDamage(30);
	ft.highFivesGuys();
}

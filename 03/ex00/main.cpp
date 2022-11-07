/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:10:16 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/07 23:01:34 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	#if PRETTY
		std::cout << "╔═══════════════╦════════════╦════════════════════════════════╦════════════╗" << std::endl;
		std::cout << "║     Event     ║    Name    ║           Description          ║  Success?  ║" << std::endl;
		std::cout << "╠═══════════════╬════════════╬════════════════════════════════╬════════════╣" << std::endl;
	#endif
	{
		ClapTrap clap1("Alice");
		ClapTrap clap2("Ariel");
		{
			ClapTrap clap3(clap1);
			ClapTrap clap4;
			clap4 = clap2;
		}
		clap1.beRepaired(10);
		clap1.beRepaired(79);
		for (size_t i = 0; i < 5; i++)
		{
			clap1.attack("Ariel");
			clap2.takeDamage(1);
		}
		clap1.takeDamage(100);
		clap1.attack("Ariel");
		for (size_t i = 0; i < 11; i++)
		{
			clap2.attack("Alice");
			clap1.takeDamage(1);
		}
		clap1.beRepaired(100);
		clap2.beRepaired(100);
	}
	#if PRETTY
		std::cout << "╚═══════════════╩════════════╩════════════════════════════════╩════════════╝" << std::endl;
	#endif
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:39:53 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/08 21:37:49 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "Default ScavTrap constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->_name = name;
	std::cout << "ScavTrap '" << name << "' constructor called." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &ref) : ClapTrap()
{
	std::cout << "ScavTrap copy constructor called." << std::endl;
	*this = ref;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap '" << this->_name << "' destroyed." << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap &ref)
{
	std::cout << "ScavTrap assignment operator called." << std::endl;
	if (this != &ref)
	{
		this->_name = ref._name;
		this->_hitPoints = ref._hitPoints;
		this->_energyPoints = ref._energyPoints;
		this->_attackDamage = ref._attackDamage;
	}
	return *this;
}

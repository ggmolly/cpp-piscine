/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:39:53 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/09 14:58:12 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("ScavTrap")
{
	std::cout << "Default ScavTrap constructor called." << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap '" << name << "' constructor called." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &ref) : ClapTrap(ref)
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

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap '" << _name << "' entered in Gate Keeper mode." << std::endl;
}


void ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " has no energy left to attack" << std::endl;
		return ;
	}
	if (this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " is dead and cannot attack." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:55:36 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/09 14:49:50 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor with name called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &ref)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	if (this != &ref)
		*this = ref;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap &ref)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
	if (this != &ref)
	{
		this->_name = ref._name;
		this->_hitPoints = ref._hitPoints;
		this->_energyPoints = ref._energyPoints;
		this->_attackDamage = ref._attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy left to attack" << std::endl;
		return ;
	}
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and cannot attack." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > static_cast<unsigned int>(_hitPoints))
	{
		std::cout << "'" << _name << "' is already dead" << std::endl;
		_hitPoints = 0;
	}
	else
	{
		std::cout << "'" << _name << "' took " << amount << " damages!" << std::endl;
		_hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy left to be repaired" << std::endl;
		return ;
	}
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and cannot be repaired" << std::endl;
		return ;
	}
	// Overflow protection
	if (amount > UINT_MAX - _hitPoints)
		amount = UINT_MAX - _hitPoints;
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << this->_name << " is repaired by " << amount << " points" << std::endl;
}

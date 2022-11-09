/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:39:53 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/09 14:58:16 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("FragTrap")
{
	std::cout << "Default FragTrap constructor called." << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_name = name;
	std::cout << "FragTrap '" << name << "' constructor called." << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap &ref) : ClapTrap(ref)
{
	std::cout << "FragTrap copy constructor called." << std::endl;
	*this = ref;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap '" << this->_name << "' destroyed." << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap &ref)
{
	std::cout << "FragTrap assignment operator called." << std::endl;
	if (this != &ref)
	{
		this->_name = ref._name;
		this->_hitPoints = ref._hitPoints;
		this->_energyPoints = ref._energyPoints;
		this->_attackDamage = ref._attackDamage;
	}
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap '" << _name << "' : gimme five !" << std::endl;
}
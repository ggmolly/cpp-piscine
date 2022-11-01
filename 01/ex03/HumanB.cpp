/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:14:47 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/01 23:14:53 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define RESET "\033[0m"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL)
{
	std::cout << GREEN << "HumanB " << this->_name << RED << " created" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << GREEN << "HumanB " << this->_name << RED << " destroyed" << std::endl;
}

void HumanB::attack(void)
{
	if (_weapon)
		std::cout << GREEN << this->_name << RESET << " attacks with their " << this->_weapon->getType() << RESET << std::endl;
	else
		std::cout << GREEN << this->_name << RESET << " has no weapon" << RESET << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
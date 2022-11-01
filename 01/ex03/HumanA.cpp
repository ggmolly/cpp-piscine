/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:06:28 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/01 23:11:53 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

# define YELLOW "\033[1;33m"
# define RED "\033[1;31m"
# define RESET "\033[0m"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon)
{
	std::cout << YELLOW << "HumanA " << this->_name << RED << " created" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << YELLOW << "HumanA " << this->_name << RED << " destroyed" << RESET << std::endl;
}

void HumanA::attack(void)
{
	std::cout << YELLOW << this->_name << RESET << " attacks with their " << this->_weapon.getType() << RESET << std::endl;
}
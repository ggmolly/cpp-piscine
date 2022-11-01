/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:02:03 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/01 23:05:31 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

# define RED "\033[1;31m"
# define RESET "\033[0m"

Weapon::Weapon(void)
{

}

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

Weapon::~Weapon(void)
{
	std::cout << RED << "Weapon " <<  "destroyed" << RESET << std::endl;
}

std::string const &Weapon::getType(void)
{
	return (this->_type);
}

void Weapon::setType(std::string newType)
{
	this->_type = newType;
}

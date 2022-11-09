/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:49:27 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/09 23:07:37 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->_type = type;
	std::cout << "WrongAnimal name constructor called" << std::endl;	
}

WrongAnimal::WrongAnimal(WrongAnimal &ref)
{
	std::cout << "WrongAnimal copy constructor called." << std::endl;
	if (this != &ref)
		*this = ref;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destroyed." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &ref)
{
	std::cout << "WrongAnimal copy assignment operator called." << std::endl;
	if (this != &ref)
		this->_type = ref._type;
	return *this;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "*glitchy noise coming from a WrongAnimal*" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return this->_type;
}
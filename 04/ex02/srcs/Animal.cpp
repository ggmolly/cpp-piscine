/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:41:16 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/10 00:03:33 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal constructor called." << std::endl;
}

Animal::Animal(Animal &animal)
{
	std::cout << "Animal copy constructor called." << std::endl;
	if (this != &animal)
		*this = animal;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called." << std::endl;
}

Animal &Animal::operator=(Animal &animal)
{
	std::cout << "Animal copy assignment operator called." << std::endl;
	if (this != &animal)
	{
		this->_type = animal._type;
	}
	return *this;
}

void	Animal::makeSound(void) const
{
	std::cout << "*default noise*" << std::endl;
}

std::string	Animal::getType(void) const
{
	return this->_type;
}

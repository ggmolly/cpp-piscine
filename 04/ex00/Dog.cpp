/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:57:19 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/09 17:08:31 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal()
{
	std::cout << "Dog constructor called." << std::endl;
	this->_type = "Dog";
}

Dog::Dog(Dog &Dog): Animal()
{
	std::cout << "Dog copy constructor called." << std::endl;
	if (this != &Dog)
		*this = Dog;
}

Dog::~Dog(void)
{
	std::cout << "Dog destroyed." << std::endl;
}

Dog &Dog::operator=(Dog &Dog)
{
	std::cout << "Dog copy assignment operator called." << std::endl;
	if (this != &Dog)
		this->_type = Dog._type;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "*bark bark*" << std::endl;
}

std::string	Dog::getType(void)
{
	return this->_type;
}

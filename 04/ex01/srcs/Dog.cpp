/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:57:19 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/14 12:19:53 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal()
{
	std::cout << "Dog constructor called." << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(Dog &dog): Animal()
{
	std::cout << "Dog copy constructor called." << std::endl;
	if (this != &dog)
	{
		*this = dog;
	}
}

Dog::~Dog(void)
{
	std::cout << "Dog destroyed." << std::endl;
	delete this->_brain;
}

Dog &Dog::operator=(Dog &Dog)
{
	std::cout << "Dog copy assignment operator called." << std::endl;
	if (this != &Dog)
	{
		this->_type = Dog._type;
		this->_brain = new Brain(*Dog._brain);
	}
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "*bark bark*" << std::endl;
}

Brain* Dog::getBrain(void) const
{
	return this->_brain;
}
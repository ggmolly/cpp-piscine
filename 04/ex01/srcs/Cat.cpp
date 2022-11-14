/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:48:12 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/14 12:19:32 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal()
{
	std::cout << "Cat constructor called." << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(Cat &cat): Animal()
{
	std::cout << "Cat copy constructor called." << std::endl;
	if (this != &cat)
		*this = cat;
}

Cat::~Cat(void)
{
	std::cout << "Cat destroyed." << std::endl;
	delete this->_brain;
}

Cat &Cat::operator=(Cat &cat)
{
	std::cout << "Cat copy assignment operator called." << std::endl;
	if (this != &cat)
	{
		this->_type = cat._type;
		this->_brain = new Brain(*cat._brain);
	}
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "*purrrrr*" << std::endl;
}

Brain* Cat::getBrain(void) const
{
	return this->_brain;
}
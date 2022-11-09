/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:48:12 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/09 17:08:23 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal()
{
	std::cout << "Cat constructor called." << std::endl;
	this->_type = "Cat";
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
}

Cat &Cat::operator=(Cat &cat)
{
	std::cout << "Cat copy assignment operator called." << std::endl;
	if (this != &cat)
		this->_type = cat._type;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "*purrrrr*" << std::endl;
}

std::string	Cat::getType(void)
{
	return this->_type;
}

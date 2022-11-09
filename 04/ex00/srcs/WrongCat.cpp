/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:05:40 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/09 23:08:34 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal()
{
	std::cout << "WrongCat constructor called." << std::endl;
}

WrongCat::WrongCat(WrongCat &ref): WrongAnimal()
{
	std::cout << "WrongCat copy constructor called." << std::endl;
	if (this != &ref)
		*this = ref;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destroyed." << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat &ref)
{
	std::cout << "WrongCat copy assignment operator called." << std::endl;
	if (this != &ref)
		this->_type = ref._type;
	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << "*glitchy noise coming from a WrongCat* -- you shouldn't hear this" << std::endl;
}
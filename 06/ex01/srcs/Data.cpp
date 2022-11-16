/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:06:42 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/16 16:11:52 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void)
{
	std::cout << "Data default constructor called." << std::endl;
}

Data::Data(std::string name, int age): _name(name), _age(age)
{
	std::cout << "Data custom constructor called." << std::endl;
}

Data::Data(Data &ref)
{
	std::cout << "Data copy constructor called." << std::endl;
	if (this != &ref)
		*this = ref;
}

Data::~Data(void)
{
	std::cout << "Data destructor called." << std::endl;
}

Data &Data::operator=(Data &ref)
{
	std::cout << "Data assignment operator called." << std::endl;
	if (this != &ref)
	{
		this->_age = ref._age;
		this->_name = ref._name;
	}
	return *this;
}

std::string Data::getName(void) const
{
	return this->_name;
}

int Data::getAge(void) const
{
	return this->_age;
}

std::ostream& operator<<(std::ostream& os, const Data &ref)
{
    os << "Data(name=" << ref.getName() << ", age=" << ref.getAge() << ")";
    return os;
}

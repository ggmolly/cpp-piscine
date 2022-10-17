/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:37:42 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/06 12:58:02 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	this->_firstName = "";
	this->_lastName = "";
	this->_nickName = "";
	this->_phoneNumber = "";
	this->_darkestSecret = "";
}

Contact::~Contact()
{

};

void	Contact::clear(void)
{
	this->_darkestSecret = "";
	this->_firstName = "";
	this->_lastName = "";
	this->_nickName = "";
	this->_phoneNumber = "";
}

void	Contact::getInfos(void)
{
	while (this->_firstName.empty())
	{
		std::cout << "First name: ";
		std::getline(std::cin, this->_firstName);
	}
	while (this->_lastName.empty())
	{
		std::cout << "Last name: ";
		std::getline(std::cin, this->_lastName);
	}
	while (this->_nickName.empty())
	{
		std::cout << "Nickname: ";
		std::getline(std::cin, this->_nickName);
	}
	while (this->_phoneNumber.empty())
	{
		std::cout << "Phone number: ";
		std::getline(std::cin, this->_phoneNumber);
	}
	while (this->_darkestSecret.empty())
	{
		std::cout << "Darkest secret: ";
		std::getline(std::cin, this->_darkestSecret);
	}
}

void	Contact::printInfos()
{
	std::cout << "First name: " << this->_firstName << std::endl;
	std::cout << "Last name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickName << std::endl;
	std::cout << "Phone number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->_darkestSecret << std::endl;
}
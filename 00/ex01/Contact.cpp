/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:37:42 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/17 14:09:03 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>

Contact::~Contact()
{

};

Contact::Contact()
{
	this->_firstName = "";
	this->_lastName = "";
	this->_nickName = "";
	this->_phoneNumber = "";
	this->_darkestSecret = "";
}

Contact::Contact(int index, std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
	this->_index = index;
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickName = nickName;
	this->_phoneNumber = phoneNumber;
	this->_darkestSecret = darkestSecret;
}

void	Contact::clear(void)
{
	this->_darkestSecret = "";
	this->_firstName = "";
	this->_lastName = "";
	this->_nickName = "";
	this->_phoneNumber = "";
}

bool	Contact::_verifyPhone(void)
{
	for (size_t i = 0; i < this->_phoneNumber.size(); i++)
	{
		if (isdigit(this->_phoneNumber[i]) == 0)
			return (false);
	}
	return (true);
}

void	Contact::getInfos(int index)
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
	while (this->_phoneNumber.empty() || !this->_verifyPhone())
	{
		std::cout << "Phone number: ";
		std::getline(std::cin, this->_phoneNumber);
	}
	while (this->_darkestSecret.empty())
	{
		std::cout << "Darkest secret: ";
		std::getline(std::cin, this->_darkestSecret);
	}
	this->_index = index;
}

void	Contact::printInfos()
{
	std::cout << "First name: " << this->_firstName << std::endl;
	std::cout << "Last name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickName << std::endl;
	std::cout << "Phone number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->_darkestSecret << std::endl;
}

void	Contact::printTableLine()
{
	std::string firstName = this->_firstName;
	std::string lastName = this->_lastName;
	std::string nickName = this->_nickName;
	int			index = this->_index;

	if (firstName.length() > 10)
		firstName = firstName.substr(0, 9) + ".";
	if (lastName.length() > 10)
		lastName = lastName.substr(0, 9) + ".";
	if (nickName.length() > 10)
		nickName = nickName.substr(0, 9) + ".";
	std::cout << "║" << std::setw(10) << index << "|";
	std::cout << std::setw(10) << firstName << "|";
	std::cout << std::setw(10) << lastName << "|";
	std::cout << std::setw(10) << nickName << "║" << std::endl;
}

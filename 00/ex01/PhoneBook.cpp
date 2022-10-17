/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:14:45 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/17 14:06:42 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>

void PhoneBook::debugContact(int index, std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
    Contact contact = Contact(index, firstName, lastName, nickName, phoneNumber, darkestSecret);
    this->_contacts[index] = contact;
}

PhoneBook::PhoneBook()
{
    this->_offset = 0;
    this->_entries = 0;
    #if DEBUG
        std::cout << "/!\\ DEBUG /!\\" << std::endl;
        this->_entries = 8;
        this->_offset = 0;
        this->debugContact(0, "John", "Doe", "jdoe", "1234567890", "I am a secret");
        this->debugContact(1, "Jane", "Doe", "jane", "0987654321", "I am a secret");
        this->debugContact(2, "Loooooooooong", "Naaaaaaaaame", "nicknaaaame", "0987654321", "I am a secret");
        this->debugContact(3, "Loooooooooong", "Naaaaaaaaame", "nicknaaaame", "0987654321", "I am a secret");
        this->debugContact(4, "Loooooooooong", "Naaaaaaaaame", "nicknaaaame", "0987654321", "I am a secret");
        this->debugContact(5, "Loooooooooong", "Naaaaaaaaame", "nicknaaaame", "0987654321", "I am a secret");
        this->debugContact(6, "Loooooooooong", "Naaaaaaaaame", "nicknaaaame", "0987654321", "I am a secret");
        this->debugContact(7, "Loooooooooong", "Naaaaaaaaame", "nicknaaaame", "0987654321", "I am a secret");
    #endif
}

PhoneBook::~PhoneBook()
{

};

void PhoneBook::_writeContact(Contact c)
{
    if (this->_offset == 8)
        this->_offset = 0;
    this->_contacts[this->_offset] = c;
    this->_offset++;
    if (this->_entries < 8)
        this->_entries++;
}

void PhoneBook::appendContact(void)
{
    Contact newContact;
    newContact.getInfos(this->_offset);
    this->_writeContact(newContact);
}

void PhoneBook::displayContacts(void)
{
    std::cout << "╔═══════════════════════════════════════════╗" << std::endl;
    std::cout << "║   index  │first name│ last name│ nickname ║" << std::endl;
    std::cout << "╠═══════════════════════════════════════════╣" << std::endl;
    if (this->_entries == 0)
    {
        std::cout << "║" << RED2 <<
            std::setw(35) << "No contacts registered !" << RESET
            << std::setw(11) << "║" << std::endl;
    }
    else
    {
        for (int i = 0; i < this->_entries; i++)
        {
            this->_contacts[i].printTableLine();
        }
    }
    std::cout << "╚═══════════════════════════════════════════╝" << std::endl;
}

Contact* PhoneBook::getContactByIndex(int index)
{
    if (index < this->_entries)
        return (&this->_contacts[index]);
    else
        return (NULL);
}

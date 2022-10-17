/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:28:09 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/17 14:09:49 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

# define RED2 "\033[38;5;124m"
# define RESET "\033[0m"
# define RESETNL "\033[0m\n"

# ifndef DEBUG
#  define DEBUG true
# endif

class PhoneBook
{
	private:
		Contact 	_contacts[8];
		short int	_offset;
		short int	_entries;
		void 		_writeContact(Contact contact);
	public:
		PhoneBook();
		~PhoneBook();
		void debugContact(int index, std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret);
		void appendContact(void);
		void displayContacts(void);
		Contact* getContactByIndex(int id);
};

#endif
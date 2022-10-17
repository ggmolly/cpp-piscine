/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:19:47 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/17 13:30:49 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "PhoneBook.hpp"

bool	num_only(std::string s)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		if (!isdigit(s[i]))
			return (false);
	}
	return (true);
}

void	print_error(std::string error)
{
	std::cout << RED2 << "error: " << error << RESETNL;
}

int	display_contact(PhoneBook *pb)
{
	pb->displayContacts();
	std::string input = "-1";
	std::cout << "Index of contact to search: ";
	std::flush(std::cout);
	if (!std::getline(std::cin, input))
	{
		std::cout << std::endl;
		print_error("cancelling search");
		return (0);
	}
	int index = atoi(input.c_str());
	if (input.empty() || (index < 0 || index > 7) || !num_only(input))
		print_error("invalid index");
	else
	{
		Contact *c;
		c = pb->getContactByIndex(index);
		if (c == NULL)
			print_error("no contact at this index");
		else
			c->printInfos();
	}
	return (1);
}

int exec_command(std::string input, PhoneBook *pb)
{
	if (strcasecmp(input.c_str(), "add") == 0)
		pb->appendContact();
	else if (strcasecmp(input.c_str(), "search") == 0)
		return (display_contact(pb));
	else if (strcasecmp(input.c_str(), "exit") == 0)
		return (0);
	else
		print_error("unknown command");
	return (1);
}

int main(void)
{
	PhoneBook pb;
	std::string cmd;

	while (true)
	{
		std::cout << "Enter command: ";
		std::flush(std::cout);
		if (!std::getline(std::cin, cmd))
		{
			std::cout << std::endl;
			break;
		}
		if (!exec_command(cmd, &pb))
			break;
	}
	return (0);
}

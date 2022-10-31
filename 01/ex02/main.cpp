/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:53:08 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/31 21:58:23 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define ORANGE "\033[31m"
# define RESET "\033[0m"

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << GREEN << "String address: " << &str << RESET << std::endl;
	std::cout << YELLOW << "Pointer address: " << stringPTR << RESET << std::endl;
	std::cout << ORANGE << "Reference address : " << &stringREF << RESET << std::endl;

	std::cout << std::endl;

	std::cout << GREEN << "Raw string : " << str << GREEN << std::endl;
	std::cout << YELLOW << "Pointed content : " << *stringPTR << YELLOW << std::endl;
	std::cout << ORANGE << "Reference content : " << stringREF << ORANGE << std::endl;

	return (0);
}

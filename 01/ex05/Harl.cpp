/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:07:15 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/02 15:00:34 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

# define SKYBLUE "\033[1;36m"
# define BLUE "\033[0;34m"
# define YELLOW "\033[1;33m"
# define RED "\033[1;31m"
# define RESET "\033[0m"

Harl::Harl(void)
{
	_levels[0] = "DEBUG";
	_functions[0] = &Harl::_debug;

	_levels[1] = "INFO";
	_functions[1] = &Harl::_info;

	_levels[2] = "WARNING";
	_functions[2] = &Harl::_warning;

	_levels[3] = "ERROR";
	_functions[3] = &Harl::_error;
}

Harl::~Harl(void)
{
}

void Harl::_debug(void)
{
	std::cout << SKYBLUE << "This is a debug message" << RESET << std::endl;
}

void Harl::_info(void)
{
	std::cout << BLUE << "This is an info message" << RESET << std::endl;
}

void Harl::_warning(void)
{
	std::cout << YELLOW << "This is a warning message" << RESET << std::endl;
}

void Harl::_error(void)
{
	std::cout << RED << "This is an error message" << RESET << std::endl;
}

void Harl::complain(std::string level)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_levels[i] == level)
		{
			(this->*_functions[i])();
			return ;
		}
	}
}
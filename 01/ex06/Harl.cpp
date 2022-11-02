/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:07:15 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/02 15:00:30 by jallerha         ###   ########.fr       */
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
	_levels[1] = "INFO";
	_levels[2] = "WARNING";
	_levels[3] = "ERROR";
	_min_level = -1;
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

void Harl::complain(void)
{
	switch (this->_min_level)
	{
		case 0:
			_debug();
			_info();
			_warning();
			_error();
			break;
		case 1:
			_info();
			_warning();
			_error();
			break;
		case 2:
			_warning();
			_error();
			break;
		case 3:
			_error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	// switch (this->_min_level)
	// {
	// 	case 0:
	// 		_debug();
	// 	case 1:
	// 		_info();
	// 	case 2:
	// 		_warning();
	// 	case 3:
	// 		_error();
	// 		break;
	// 	default:
	// 		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	// }
}

void Harl::setLevel(std::string level)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (_levels[i] == level)
		{
			_min_level = i;
			return ;
		}
	}
	_min_level = -1;
}

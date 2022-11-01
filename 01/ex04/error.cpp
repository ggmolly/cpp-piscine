/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:19:46 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/01 23:22:36 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "betterSed.hpp"

void	print_error(std::string description)
{
	std::cout << RED << "error: " << RESET << description << std::endl;
}

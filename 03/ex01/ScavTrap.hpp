/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:38:07 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/08 13:42:01 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap: ClapTrap
{
	private:
		
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap &ref);
		~ScavTrap(void);
		ScavTrap &operator=(ScavTrap &ref);
};
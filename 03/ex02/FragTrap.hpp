/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:38:07 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/09 14:21:52 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"
#include <iostream>

class FragTrap: public ClapTrap
{
	private:
		
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap &ref);
		~FragTrap(void);
		FragTrap &operator=(FragTrap &ref);
		void highFivesGuys(void);
};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:39:45 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/09 17:26:18 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>

class Animal
{
	protected:
		std::string _type;
	public:
		Animal(void);
		Animal(Animal &animal);
		virtual ~Animal(void);
		Animal &operator=(Animal &animal);
		virtual void makeSound(void) const;
		std::string	 getType(void) const;
};
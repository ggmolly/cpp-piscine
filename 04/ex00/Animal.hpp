/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:39:45 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/09 17:15:53 by jallerha         ###   ########.fr       */
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
		~Animal(void);
		Animal &operator=(Animal &animal);
		void		makeSound(void) const;
		std::string	getType(void);
};
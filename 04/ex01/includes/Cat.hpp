/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:37:52 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/09 23:40:58 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "Animal.hpp"

class Cat : public Animal
{
	private:
		Brain *_brain;
	public:
		Cat(void);
		Cat(Cat &cat);
		~Cat(void);
		Cat &operator=(Cat &cat);
		void		makeSound(void) const;
		Brain 		*getBrain(void) const;
};
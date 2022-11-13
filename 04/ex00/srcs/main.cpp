/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:58:16 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/13 14:51:35 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

# define PLUM1 "\033[38;5;219m"
# define PLUM2 "\033[38;5;183m"
# define PLUM3 "\033[38;5;176m"
# define PLUM4 "\033[38;5;96m"
# define SPRINGGREEN1 "\033[38;5;48m"
# define RESET "\033[0m"
# define RED1 "\033[38;5;196m"

int main(void)
{
	{
		const Animal *generic = new Animal();
		const Animal *dog = new Dog();
		const Animal *cat = new Cat();

		std::cout << PLUM1 << "Generic animal says: " << SPRINGGREEN1;
		generic->makeSound();
		std::cout << PLUM2 << "Dog says: " << SPRINGGREEN1;
		dog->makeSound();
		std::cout << PLUM3 << "Cat says: " << SPRINGGREEN1;
		cat->makeSound();
		std::cout << RED1 << "-------------------------" << RESET << std::endl;
		delete generic;
		delete dog;
		delete cat;
	}
	std::cout << std::endl;
	{
		const WrongAnimal *wrong = new WrongAnimal();
		const WrongAnimal *wrongCat = new WrongCat();

		std::cout << PLUM4 << "Wrong animal says: " << SPRINGGREEN1;
		wrong->makeSound();
		std::cout << PLUM1 << "WrongCat says: " << SPRINGGREEN1;
		wrongCat->makeSound();
		std::cout << RED1 << "-------------------------" << RESET << std::endl;
		delete wrong;
		delete wrongCat;
	}
	std::cout << std::endl;
	{
		const WrongCat *wrongCat = new WrongCat();

		std::cout << PLUM1 << "WrongCat says: " << SPRINGGREEN1;
		wrongCat->makeSound();
		std::cout << RED1 << "-------------------------" << RESET << std::endl;
		delete wrongCat;
	}
}

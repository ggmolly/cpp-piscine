/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:58:16 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/13 15:19:40 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"

# define SPRINGGREEN3 "\033[38;5;47m"
# define RED1 "\033[38;5;196m"
# define RESET "\033[0m"
# define YELLOW1 "\033[38;5;226m"

# define N_ANIMALS 4

void fillBrain(Dog *dog)
{
	Brain *brain = dog->getBrain();
	for (size_t i = 0; i < 100; i++)
	{
		brain->setIdea(i, "Idea");
	}
}

void fillBrain(Cat *cat)
{
	Brain *brain = cat->getBrain();
	for (size_t i = 0; i < 100; i++)
	{
		brain->setIdea(i, "Idea");
	}
}

bool checkCopy(Brain *brain)
{
	for (size_t i = 0; i < 100; i++)
	{
		if (brain->getIdea(i) != "Idea")
		{
			return false;
		}
	}
	return true;
}

int main(void)
{
	Animal *animals[N_ANIMALS];
	
	std::cout << "========= Create animals =========" << std::endl;
	for (size_t i = 0; i < N_ANIMALS / 2; i++)
	{
		animals[i] = new Dog();
		fillBrain((Dog *)animals[i]);
	}
	for (size_t i = N_ANIMALS / 2; i < N_ANIMALS; i++)
	{
		animals[i] = new Cat();
		fillBrain((Cat *)animals[i]);
	}
	std::cout << "========= Checking sounds =========" << std::endl;
	for (size_t i = 0; i < N_ANIMALS; i++)
	{
		animals[i]->makeSound();
	}
	std::cout << "========= Checking addresses =========" << std::endl;
	for (size_t i = 0; i < N_ANIMALS; i++)
	{
		std::cout << animals[i]->getBrain() << std::endl;
	}
	std::cout << "========= Testing brain copy =========" << std::endl;
	// Create a copy of last animal
	Animal *copies[N_ANIMALS];
	// Use copy constructors
	for (size_t i = 0; i < N_ANIMALS / 2; i++)
	{
		copies[i] = new Dog(*(Dog *)animals[i]);
	}
	for (size_t i = N_ANIMALS / 2; i < N_ANIMALS; i++)
	{
		copies[i] = new Cat(*(Cat *)animals[i]);
	}
	for (size_t i = 0; i < N_ANIMALS; i++)
	{
		copies[i]->getBrain()->setIdea(0, "Idea changed");
	}
	for (size_t i = 0; i < N_ANIMALS; i++)
	{
		if (animals[i]->getBrain()->getIdea(0) == "Idea changed")
		{
			std::cout << RED1 << "Brain copy failed" << RESET << YELLOW1 << " -- " << animals[i]->getBrain() << " / " << copies[i]->getBrain() << RESET << std::endl;
		}
		else
		{
			std::cout << SPRINGGREEN3 << "Brain copy success" << RESET << YELLOW1 << " -- " << animals[i]->getBrain() << " / " << copies[i]->getBrain() << RESET << std::endl;
		}
	}
	std::cout << "========= Destroy animals =========" << std::endl;
	for (size_t i = 0; i < N_ANIMALS; i++)
	{
		delete animals[i];
	}
	std::cout << "========= Destroy copies =========" << std::endl;
	for (size_t i = 0; i < N_ANIMALS; i++)
	{
		delete copies[i];
	}
}

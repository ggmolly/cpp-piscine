/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:58:16 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/10 00:10:06 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"

#define N_ANIMALS 10

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
	std::cout << "========= Checking copy =========" << std::endl;
	for (size_t i = 0; i < N_ANIMALS; i++)
	{
		Brain *brain = animals[i]->getBrain();
		if (checkCopy(brain))
		{
			std::cout << "Brain successfully copied (deep copy)" << std::endl;
		}
		else
		{
			std::cout << "Brain not copied (shallow copy)" << std::endl;
		}
	}
	std::cout << "========= Destroy animals =========" << std::endl;
	for (size_t i = 0; i < N_ANIMALS; i++)
	{
		delete animals[i];
	}
}

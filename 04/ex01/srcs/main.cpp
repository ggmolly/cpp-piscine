/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:58:16 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/14 13:10:40 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"

# define SPRINGGREEN3 "\033[38;5;47m"
# define RED1 "\033[38;5;196m"
# define RESET "\033[0m"
# define YELLOW1 "\033[38;5;226m"
# define PLUM2 "\033[38;5;183m"

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
	}
	for (size_t i = N_ANIMALS / 2; i < N_ANIMALS; i++)
	{
		animals[i] = new Cat();
	}
	std::cout << "========= Checking sounds =========" << std::endl;
	for (size_t i = 0; i < N_ANIMALS; i++)
	{
		animals[i]->makeSound();
	}
	std::cout << "========= Delete animal =========" << std::endl;
	for (size_t i = 0; i < N_ANIMALS; i++)
	{
		delete animals[i];
	}
	Cat *cat = new Cat();
	Dog *dog = new Dog();
	fillBrain(cat);
	fillBrain(dog);
	Cat *copyCat = new Cat(*cat);
	Dog *copyDog = new Dog(*dog);
	std::cout << "========= Checking addresses =========" << std::endl;
	std::cout << "Cat: " << cat->getBrain() << std::endl;
	std::cout << "Dog: " << dog->getBrain() << std::endl;
	std::cout << "CopyCat: " << copyCat->getBrain() << std::endl;
	std::cout << "CopyDog: " << copyDog->getBrain() << std::endl;
	std::cout << "========= Testing brain copy =========" << std::endl;
	copyCat->getBrain()->setIdea(0, "Idea changed");
	copyDog->getBrain()->setIdea(0, "Idea changed");
	if (cat->getBrain()->getIdea(0) == "Idea changed")
	{
		std::cout << RED1 << "Brain copy failed" << RESET << YELLOW1 << " -- " << PLUM2 << cat->getBrain() << " / " << copyCat->getBrain() << RESET << std::endl;
	}
	else
	{
		std::cout << SPRINGGREEN3 << "Brain copy success" << RESET << YELLOW1 << " -- " << PLUM2 << cat->getBrain() << " / " << copyCat->getBrain() << RESET << std::endl;
	}
	if (dog->getBrain()->getIdea(0) == "Idea changed")
	{
		std::cout << RED1 << "Brain copy failed" << RESET << YELLOW1 << " -- " << PLUM2 << dog->getBrain() << " / " << copyDog->getBrain() << RESET << std::endl;
	}
	else
	{
		std::cout << SPRINGGREEN3 << "Brain copy success" << RESET << YELLOW1 << " -- " << PLUM2 << dog->getBrain() << " / " << copyDog->getBrain() << RESET << std::endl;
	}
	delete cat;
	delete dog;
	delete copyCat;
	delete copyDog;
	std::cout << "========= Creating generic Animal =========" << std::endl;
	Animal a;
	a.makeSound();
}

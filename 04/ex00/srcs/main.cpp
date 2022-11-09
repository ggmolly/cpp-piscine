/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:58:16 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/09 23:09:20 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"

/* -------- Stack tests -------- */
void animalStack()
{
	std::cout << ">>> (stack) Default Animal <<<" << std::endl;
	Animal defaultAnimal;
	std::cout << "Type : " << defaultAnimal.getType() << std::endl;
	defaultAnimal.makeSound();
}

void catStack()
{
	std::cout << "\n>>> (stack) Cat <<<" << std::endl;
	Cat cat;
	std::cout << "Type : " << cat.getType() << std::endl;
	cat.makeSound();
}

void dogStack()
{
	std::cout << "\n>>> (stack) Dog <<<" << std::endl;
	Dog dog;
	std::cout << "Type : " << dog.getType() << std::endl;
	dog.makeSound();
}

/* -------- Heap tests -------- */

void animalHeap()
{
	std::cout << ">>> (heap) Default Animal <<<" << std::endl;
	Animal *defaultAnimal = new Animal();
	std::cout << "Type : " << defaultAnimal->getType() << std::endl;
	defaultAnimal->makeSound();
	delete defaultAnimal;
}

void catHeap()
{
	std::cout << "\n>>> (heap) Cat <<<" << std::endl;
	Cat *cat = new Cat();
	std::cout << "Type : " << cat->getType() << std::endl;
	cat->makeSound();
	delete cat;
}

void dogHeap()
{
	std::cout << "\n>>> (heap) Dog <<<" << std::endl;
	Dog *dog = new Dog();
	std::cout << "Type : " << dog->getType() << std::endl;
	dog->makeSound();
	delete dog;
}

void heapTests()
{
	animalHeap();
	catHeap();
	dogHeap();
	std::cout << std::endl;
}

void stackTests()
{
	animalStack();
	catStack();
	dogStack();
	std::cout << std::endl;
}

/* -------- WrongAnimal tests -------- */

void wrongTests()
{
	std::cout << ">>> WrongCat <<<" << std::endl;
	WrongAnimal *wrongCat = new WrongAnimal();
	std::cout << "Type : " << wrongCat->getType() << std::endl;
	wrongCat->makeSound();
	delete wrongCat;
}

/* -------- Main -------- */

int main(void)
{
	stackTests();
	heapTests();
	wrongTests();
}
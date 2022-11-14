/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 22:17:41 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/14 22:48:36 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

# define RED1 "\033[38;5;196m"
# define SPRINGGREEN3 "\033[38;5;47m"
# define DODGERBLUE2 "\033[38;5;27m"
# define RESET "\033[0m"

void	runTest(std::string name, int grade)
{
	try
	{
		Bureaucrat b(name, grade);
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED1 << "Failed to create Bureaucrat : " << e.what() << RESET << std::endl;
	}
}

void tryDecrease(Bureaucrat &ref)
{
	try
	{
		std::cout << DODGERBLUE2 << "Trying to decrease grade of " << ref.getName() << RESET << std::endl;
		ref.decreaseGrade();
		std::cout << ref << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED1 << "Failed to decrease : " << e.what() << RESET << std::endl;
	}
}

void tryIncrease(Bureaucrat &ref)
{
	try
	{
		std::cout << DODGERBLUE2 << "Trying to increase grade of " << ref.getName() << RESET << std::endl;
		ref.increaseGrade();
		std::cout << ref << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED1 << "Failed to increase : " << e.what() << RESET << std::endl;
	}
}

int main(void)
{
	std::cout << "╔═══════════════════╗" << std::endl;
	std::cout << "║" << DODGERBLUE2 << "    VALID GRADE    " << RESET << "║" << std::endl;
	std::cout << "╚═══════════════════╝" << std::endl;
	runTest("Alice", 1);
	runTest("Carol", 25);
	runTest("Carlos", 50);
	runTest("Charlie", 75);
	runTest("Erin", 100);
	runTest("Bob", 150);
	std::cout << std::endl;

	std::cout << "╔═══════════════════╗" << std::endl;
	std::cout << "║" << RED1 << "   INVALID GRADE   " << RESET << "║" << std::endl;
	std::cout << "╚═══════════════════╝" << std::endl;
	runTest("Chuck", 151);
	runTest("Chad", 0);
	runTest("Craig", -1);
	std::cout << std::endl;

	std::cout << "╔══════════════════════╗" << std::endl;
	std::cout << "║" << RED1 << " MALICIOUS DECREMENTS " << RESET << "║" << std::endl;
	std::cout << "╚══════════════════════╝" << std::endl;
	{
		Bureaucrat b("LowBound", 148);
		std::cout << "Initial : " << b << std::endl;
		tryDecrease(b);
		tryDecrease(b);
		tryDecrease(b);
	}
	std::cout << std::endl;

	std::cout << "╔══════════════════════╗" << std::endl;
	std::cout << "║" << RED1 << " MALICIOUS INCREMENTS " << RESET << "║" << std::endl;
	std::cout << "╚══════════════════════╝" << std::endl;
	{
		Bureaucrat b("HighBound", 2);
		std::cout << "Initial : " << b << std::endl;
		tryIncrease(b);
		tryIncrease(b);
		tryIncrease(b);
	}
}
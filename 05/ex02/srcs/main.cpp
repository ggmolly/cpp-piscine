/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 22:17:41 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/16 00:05:00 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <stdlib.h>

# define RED1 "\033[38;5;196m"
# define SPRINGGREEN3 "\033[38;5;47m"
# define DODGERBLUE2 "\033[38;5;27m"
# define RESET "\033[0m"

void trySign(Form &ref, Bureaucrat &b)
{
	try
	{
		ref.beSigned(b);
		std::cout << SPRINGGREEN3 << "Form " << ref.getName() << " signed by " << b.getName() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Failed to sign form : " << RED1 << e.what() << RESET << '\n';
	}
}

int main(void)
{
	srand(time(NULL));
	std::cout << "╔════════════════════════════════════════╗" << std::endl;
	std::cout << "║                                        ║" << std::endl;
	std::cout << "║" << DODGERBLUE2 << "              ShrubberyForm             " << RESET << "║" << std::endl;
	std::cout << "║                                        ║" << std::endl;
	std::cout << "╚════════════════════════════════════════╝" << std::endl;
	{
		ShrubberyCreationForm f("tree");
		Bureaucrat b("Bob", 1);
		Bureaucrat b1("Alice", 146);
		b.executeForm(f);
		b1.executeForm(f);
		trySign(f, b1);
		b1.executeForm(f);
		trySign(f, b);
		b1.executeForm(f);
		b.executeForm(f);
	}
	std::cout << "╔════════════════════════════════════════╗" << std::endl;
	std::cout << "║                                        ║" << std::endl;
	std::cout << "║" << DODGERBLUE2 << "               RobotomyForm             " << RESET << "║" << std::endl;
	std::cout << "║                                        ║" << std::endl;
	std::cout << "╚════════════════════════════════════════╝" << std::endl;
	{
		RobotomyRequestForm f("Craig");
		Bureaucrat b("Alice", 1);
		Bureaucrat b1("Bob", 70);
		b.executeForm(f);
		b1.executeForm(f);
		trySign(f, b1);
		trySign(f, b);
		b1.executeForm(f);
		for (size_t i = 0; i < 5; i++)
		{
			b.executeForm(f);
		}
	}
	std::cout << "╔════════════════════════════════════════╗" << std::endl;
	std::cout << "║                                        ║" << std::endl;
	std::cout << "║" << DODGERBLUE2 << "            PresidentialForm            " << RESET << "║" << std::endl;
	std::cout << "║                                        ║" << std::endl;
	std::cout << "╚════════════════════════════════════════╝" << std::endl;
	{
		PresidentialPardonForm f("Eve");
		Bureaucrat b("Alice", 1);
		Bureaucrat b1("Bob", 26);
		b.executeForm(f);
		b1.executeForm(f);
		trySign(f, b1);
		trySign(f, b);
		b1.executeForm(f);
		b.executeForm(f);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 22:17:41 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/15 01:06:34 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

# define RED1 "\033[38;5;196m"
# define SPRINGGREEN3 "\033[38;5;47m"
# define DODGERBLUE2 "\033[38;5;27m"
# define RESET "\033[0m"

void tryCreateForm(std::string name, int execGrade, int signGrade)
{
	try
	{
		Form f(name, execGrade, signGrade);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED1 << "Failed to create Form : " << e.what() << RESET << std::endl;
	}
}

void trySign(int bureaucrateGrade, std::string name, int execGrade, int signGrade)
{
	try
	{
		Bureaucrat b("Bureaucrat", bureaucrateGrade);
		Form f(name, execGrade, signGrade);
		std::cout << b << std::endl;
		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED1 << "Failed to sign Form : " << e.what() << RESET << std::endl;
	}
}

int main(void)
{
	std::cout << "╔════════════════════╗" << std::endl;
	std::cout << "║" << DODGERBLUE2 << "    VALID GRADES    " << RESET << "║" << std::endl;
	std::cout << "╚════════════════════╝" << std::endl;
	tryCreateForm("Form1", 1, 1);
	tryCreateForm("Form25", 25, 25);
	tryCreateForm("Form50", 50, 50);
	tryCreateForm("Form75", 75, 75);
	tryCreateForm("Form100", 100, 100);
	tryCreateForm("Form125", 125, 125);
	tryCreateForm("Form150", 150, 150);
	std::cout << std::endl;

	std::cout << "╔════════════════════╗" << std::endl;
	std::cout << "║" << RED1 << "   INVALID GRADES   " << RESET << "║" << std::endl;
	std::cout << "╚════════════════════╝" << std::endl;
	tryCreateForm("Form0", 0, 0);
	tryCreateForm("Form-1", -1, -1);
	tryCreateForm("Form151", 151, 151);
	tryCreateForm("Form200", 200, 200);
	std::cout << std::endl;

	std::cout << "╔════════════════════╗" << std::endl;
	std::cout << "║" << DODGERBLUE2 << "      SIGNABLE      " << RESET << "║" << std::endl;
	std::cout << "╚════════════════════╝" << std::endl;
	trySign(1, "Form1", 1, 1);
	trySign(1, "Form100", 100, 100);
	trySign(2, "FormLow", 150, 150);

	std::cout << "╔════════════════════╗" << std::endl;
	std::cout << "║" << RED1 << "     UNSIGNABLE     " << RESET << "║" << std::endl;
	std::cout << "╚════════════════════╝" << std::endl;
	trySign(150, "BureaucrateMin", 1, 1);
	trySign(10, "10-2-2", 2, 2);
	trySign(150, "150-149-149", 149, 149);
	
}
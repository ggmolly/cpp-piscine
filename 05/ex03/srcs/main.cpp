/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 22:17:41 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/16 01:16:56 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <stdlib.h>

# define RED1 "\033[38;5;196m"
# define SPRINGGREEN3 "\033[38;5;47m"
# define DODGERBLUE2 "\033[38;5;27m"
# define RESET "\033[0m"

int main(void)
{
	Intern someRandomIntern;
	Form* rrf;
	std::cout << someRandomIntern << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Robotomy");
	std::cout << *rrf << std::endl;
	delete rrf;
	rrf = someRandomIntern.makeForm("shrubbery creation", "Shrubbery");
	std::cout << *rrf << std::endl;
	delete rrf;
	rrf = someRandomIntern.makeForm("presidential pardon", "Presidential");
	std::cout << *rrf << std::endl;
	delete rrf;
	try
	{
		rrf = someRandomIntern.makeForm("asihjdsihjaihdjashdajhj", "This does not exist");
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED1 << "Exception caught : " << e.what() << RESET << std::endl;
	}
}
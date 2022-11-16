/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 00:23:07 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/16 01:16:06 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include <cstring>

Intern::Intern(void)
{
	std::cout << "Intern created" << std::endl;
}

Intern::Intern(Intern &ref)
{
	if (this != &ref)
		*this = ref;
}

Intern::~Intern(void)
{
	std::cout << "Intern destroyed" << std::endl;
}

Intern &Intern::operator=(Intern &ref)
{
	if (this != &ref)
		*this = ref;
	return *this;
}

Form *Intern::makeForm(std::string name, std::string target)
{
	t_types types[3] = {
		{"presidential pardon", new PresidentialPardonForm(target)},
		{"robotomy request", new RobotomyRequestForm(target)},
		{"shrubbery creation", new ShrubberyCreationForm(target)}};
	Form *output = NULL;
	for (int i = 0; i < 3; i++)
	{
		if (strcasecmp(types[i].type.c_str(), name.c_str()) == 0)
		{
			std::cout << "Intern creates " << name << std::endl;
			output = types[i].formTemplate;
		}
		else
			delete types[i].formTemplate;
	}
	if (!output)
		throw Intern::FormNotFoundException();
	return output;
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return "Form not found";
}

std::ostream &operator<<( std::ostream & os, Intern const &ref)
{
	(void) ref;
	os << "An Intern";
	return os;
}
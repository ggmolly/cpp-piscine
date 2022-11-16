/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:57:07 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/16 01:13:12 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"
# include <fstream>

# define RED1 "\033[38;5;196m"
# define RESET "\033[0m"

PresidentialPardonForm::PresidentialPardonForm(void):
Form("PresidentialPardonForm", 25, 5),
_target("")
{
	// std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name):
Form("PresidentialPardonForm", 25, 5),
_target(name)
{
	// std::cout << "PresidentialPardonForm '" << name << "' constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &ref): Form(ref)
{
	// std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	if (this != &ref)
		*this = ref;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	// std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &ref)
{
	// std::cout << "PresidentialPardonForm assignation operator called" << std::endl;
	if (this != &ref)
	{
		_target = ref._target;
	}
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->isSigned())
		throw Form::NotSignedException();
	if (executor.getGrade() > this->getGradeExecReq())
		throw Form::GradeTooLowException();
	std::cout << "PresidentialPardonForm '" << this->getName() << "' executed by '" << executor.getName() << "'" << std::endl;
	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

Form* PresidentialPardonForm::create(std::string target)
{
	return new PresidentialPardonForm(target);
}

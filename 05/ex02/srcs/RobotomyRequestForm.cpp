/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:57:07 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/15 23:06:25 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"
# include <fstream>
# include <stdlib.h>

# define RED1 "\033[38;5;196m"
# define PLUM1 "\033[38;5;129m"
# define RESET "\033[0m"

RobotomyRequestForm::RobotomyRequestForm(void):
Form("RobotomyRequestForm", 72, 45),
_target("")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name):
Form("RobotomyRequestForm", 72, 45),
_target(name)
{
	std::cout << "RobotomyRequestForm '" << name << "' constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &ref): Form(ref)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	if (this != &ref)
		*this = ref;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &ref)
{
	std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
	if (this != &ref)
	{
		_target = ref._target;
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->isSigned())
		throw Form::NotSignedException();
	if (executor.getGrade() > this->getGradeExecReq())
		throw Form::GradeTooLowException();
	std::cout << "RobotomyRequestForm '" << this->getName() << "' executed by '" << executor.getName() << "'" << std::endl;
	std::cout << "*brrrrrrrrrrrrrrrrrrrrrrrrr* ";
	if (rand() % 2)
		std::cout << PLUM1 << this->_target << " has been robotomized successfully" << RESET << std::endl;
	else
		std::cout << RED1 << this->_target << " robotomization failed" << RESET << std::endl;
}
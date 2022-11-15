/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 22:06:16 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/15 00:52:53 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

# define MAGENTA1 "\033[38;5;201m"
# define MAGENTA3 "\033[38;5;200m"
# define MAGENTA2 "\033[38;5;165m"
# define MAGENTA6 "\033[38;5;164m"
# define MAGENTA5 "\033[38;5;163m"
# define MAGENTA4 "\033[38;5;127m"
# define RED1 "\033[38;5;196m"
# define RESET "\033[0m"

Bureaucrat::Bureaucrat(void): _grade(150)
{
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	std::cout << "Constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat &ref)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &ref)
		*this = ref;
}

Bureaucrat::~Bureaucrat(void)
{
	if (this->_name.size() > 1)
	{
		std::cout << "Destructor for '" << _name << "' called" << std::endl;
	}
	else
	{
		std::cout << "Destructor called" << std::endl;
	}
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &ref)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &ref)
		_grade = ref._grade;
	return *this;
}

/** ====== GETTERS ====== **/
std::string Bureaucrat::getName(void) const
{
	return _name;
}

int Bureaucrat::getGrade(void) const
{
	return _grade;
}

/** ====== SETTERS ====== **/
void Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
}

void Bureaucrat::increaseGrade(void)
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

void Bureaucrat::decreaseGrade(void)
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

void Bureaucrat::signForm(Form &ref)
{
	try
	{
		ref.beSigned(*this);
		std::cout << MAGENTA1 << _name << RESET << " signed " << MAGENTA2 << ref.getName() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED1 << _name << RESET << " couldn't sign " << MAGENTA2 << ref.getName() << RESET << " because " << RED1 << e.what() << RESET << std::endl;
	}
}

/** ====== EXCEPTIONS ====== **/

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

/** Misc operators **/

std::ostream& operator<<(std::ostream& os, const Bureaucrat &ref)
{
	std::string colors[6] = {MAGENTA1, MAGENTA3, MAGENTA2, MAGENTA6, MAGENTA5, MAGENTA4};
	std::string name = ref.getName();
	int grade = ref.getGrade();

	int color = (grade / 26) % 6;
	if (name.size() > 1)
		os << name << ", bureaucrat grade " << colors[color] << grade << RESET;
	else
		os << "Anonymous Bureaucrat" << ", bureaucrat grade " << colors[color] << grade << RESET;
	return (os);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:38:19 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/15 23:53:46 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"
# define MAGENTA1 "\033[38;5;201m"
# define MAGENTA3 "\033[38;5;200m"
# define MAGENTA2 "\033[38;5;165m"
# define MAGENTA6 "\033[38;5;164m"
# define MAGENTA5 "\033[38;5;163m"
# define MAGENTA4 "\033[38;5;127m"
# define RED1 "\033[38;5;196m"
# define RESET "\033[0m"

Form::Form(void): _formName("default"), _gradeSignRequirement(150), _gradeExecRequirement(150), _isSigned(false)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int signReq, int execReq):
_formName(name),
_gradeSignRequirement(signReq),
_gradeExecRequirement(execReq),
_isSigned(false)
{
	if (signReq < 1 || execReq < 1)
		throw Form::GradeTooHighException();
	else if (signReq > 150 || execReq > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(Form &ref):
_formName(ref.getName()),
_gradeSignRequirement(ref.getGradeSignReq()),
_gradeExecRequirement(ref.getGradeExecReq()),
_isSigned(ref.isSigned())
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form(void)
{
	if (_formName.size() > 1)
		std::cout << "Form '" << _formName << "' destroyed" << std::endl;
	else
		std::cout << "Un-named Form destroyed" << std::endl;
}

Form &Form::operator=(Form &ref)
{
	std::cout << "Form assignation operator called" << std::endl;
	if (this != &ref)
		_isSigned = ref.isSigned();
	return *this;
}


/** ====== GETTERS ====== **/
std::string Form::getName(void) const
{
	return _formName;
}

int Form::getGradeSignReq(void) const
{
	return _gradeSignRequirement;
}

int Form::getGradeExecReq(void) const
{
	return _gradeExecRequirement;
}

bool Form::isSigned(void) const
{
	return _isSigned;
}

/** ====== SETTERS ====== **/
void Form::setSigned(bool state)
{
	_isSigned = state;
}

/** ====== METHODS ====== **/

void Form::beSigned(Bureaucrat &ref)
{
	if (ref.getGrade() <= _gradeSignRequirement)
		_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

/** ====== EXCEPTIONS ====== **/
const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char *Form::NotSignedException::what() const throw()
{
	return "Form isn't signed";
}

/** Misc operators **/

std::ostream& operator<<(std::ostream& os, const Form &ref)
{
	std::string colors[6] = {MAGENTA1, MAGENTA3, MAGENTA2, MAGENTA6, MAGENTA5, MAGENTA4};
	std::string name = ref.getName();
	int execRequiredGrade = ref.getGradeExecReq();
	int signRequiredGrade = ref.getGradeSignReq();

	int execColor = (execRequiredGrade / 26) % 6;
	int signColor = (signRequiredGrade / 26) % 6;
	if (name.size() > 1)
		os << "Form '" << name << "' ~ " << colors[signColor] << "Grade required to sign: " << signRequiredGrade << RESET << " ~ " << colors[execColor] << "Grade required to execute: " << execRequiredGrade << RESET << " ~ " << "Signed: " << ref.isSigned() << RESET;
	else
		os << "Unnamed Form" << " ~ " << colors[signColor] << "Grade required to sign: " << signRequiredGrade << RESET << " ~ " << colors[execColor] << "Grade required to execute: " << execRequiredGrade << RESET << " ~ " << "Signed: " << ref.isSigned() << RESET;
	return (os);
}
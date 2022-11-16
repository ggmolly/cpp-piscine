/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 22:04:23 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/15 23:47:48 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string _name;
		int 			  _grade;

	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat &ref);
		~Bureaucrat(void);
		Bureaucrat &operator=(Bureaucrat &ref);

		/** ====== GETTERS ====== **/
		std::string getName(void) const;
		int getGrade(void) const;

		/** ====== SETTERS ====== **/
		void setGrade(int grade);

		/** ====== INC / DEC ====== **/
		void increaseGrade(void);
		void decreaseGrade(void);

		/** ====== METHODS ====== **/
		void signForm(Form &ref);
		void executeForm(Form const & form);

		/** ====== EXCEPTIONS ====== **/

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &ref);
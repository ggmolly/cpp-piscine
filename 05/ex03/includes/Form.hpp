/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:35:40 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/16 01:12:06 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string 	_formName;
		const int 			_gradeSignRequirement;
		const int 			_gradeExecRequirement;
		bool 				_isSigned;

	public:
		Form(void);
		Form(std::string, int, int);
		Form(Form &ref);
		virtual ~Form(void);
		Form &operator=(Form &ref);

		/** ====== GETTERS ====== **/
		std::string getName(void) const;
		int getGradeSignReq(void) const;
		int getGradeExecReq(void) const;
		bool isSigned(void) const;

		/** ====== SETTERS ====== **/
		void setSigned(bool isSigned);

		/** ====== METHODS ====== **/
		void beSigned(Bureaucrat &ref);
		virtual void execute(Bureaucrat const & executor) const = 0;
		Form *create(std::string target);

		/** ====== EXCEPTIONS ====== **/
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
		class NotSignedException : public std::exception {
			public:
				const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form &ref);
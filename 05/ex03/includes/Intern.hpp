/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 00:19:46 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/16 01:15:26 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "Form.hpp"

typedef struct s_types
{
	std::string type;
	Form *formTemplate;
}				t_types;

class Intern
{
	private:

	public:
		Intern(void);
		Intern(Intern &ref);
		~Intern(void);
		Intern &operator=(Intern &ref);
		Form *makeForm(std::string name, std::string target);
		class FormNotFoundException : public std::exception {
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<( std::ostream & os, Intern const &ref);
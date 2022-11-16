/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:57:07 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/16 00:44:34 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "Form.hpp"

class PresidentialPardonForm: public Form
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string name);
		PresidentialPardonForm(PresidentialPardonForm &ref);
		~PresidentialPardonForm(void);
		PresidentialPardonForm &operator=(PresidentialPardonForm &ref);
		void execute(Bureaucrat const & executor) const;
		Form* create(std::string target);
};
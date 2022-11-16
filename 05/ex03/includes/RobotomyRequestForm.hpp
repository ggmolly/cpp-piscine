/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:57:07 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/15 19:45:45 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "Form.hpp"

class RobotomyRequestForm: public Form
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string name);
		RobotomyRequestForm(RobotomyRequestForm &ref);
		~RobotomyRequestForm(void);
		RobotomyRequestForm &operator=(RobotomyRequestForm &ref);
		void execute(Bureaucrat const & executor) const;
		Form* create(std::string target);
};
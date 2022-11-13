/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:17:32 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/13 14:55:23 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain created" << std::endl;
}

Brain::Brain(Brain &brain)
{
	std::cout << "Brain copied" << std::endl;
	if (this != &brain)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = brain._ideas[i];
	}
}

Brain::~Brain(void)
{
	std::cout << "Brain destroyed" << std::endl;
}

Brain &Brain::operator=(Brain &brain)
{
	std::cout << "Brain assigned" << std::endl;
	if (this != &brain)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = brain._ideas[i];
	}
	return (*this);
}

void Brain::setIdea(int i, std::string idea)
{
	this->_ideas[i % 100] = idea;
}

std::string Brain::getIdea(int i) const
{
	return (this->_ideas[i % 100]);
}

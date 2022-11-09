/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:16:47 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/09 23:53:37 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];
	public:
		Brain(void);
		Brain(Brain &brain);
		~Brain(void);
		Brain &operator=(Brain &brain);
		void setIdea(int i, std::string idea);
		std::string getIdea(int i) const;
};
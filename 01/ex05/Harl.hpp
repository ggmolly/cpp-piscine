/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:07:16 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/02 14:39:30 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Harl
{
	private:
		void _debug(void);
		void _info(void);
		void _warning(void);
		void _error(void);
		std::string _levels[4];
		void (Harl::* _functions[4])(void);
	public:
		Harl(void);
		~Harl(void);
		void complain(std::string level);
};

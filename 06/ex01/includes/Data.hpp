/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:05:23 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/16 16:11:30 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Data
{
	private:
		std::string _name;
		int			_age;
	public:
		Data(void);
		Data(std::string name, int age);
		Data(Data &ref);
		~Data(void);
		Data &operator=(Data &ref);
		std::string getName(void) const;
		int			getAge(void) const;
};

std::ostream& operator<<(std::ostream& os, const Data &ref);
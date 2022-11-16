/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:02:09 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/16 14:52:01 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

bool isNumber(std::string s)
{
	if (s[0] == '-' || s[0] == '+')
		s = s.substr(1);
	for (size_t i = 0; i < s.size(); i++)
		if (isdigit(s[i]) == false)
			return false;
	return true;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid usage : " << argv[0] << " <anything>" << std::endl;
		return (1);
	}

	std::string arg(argv[1]);
	double d;

	if (arg.size() == 1 && !isdigit(arg[0]))
		d = static_cast<double>(arg[0]);
	else
		d = strtod(arg.c_str(), NULL);

	displayChar(d);
	displayInt(d);
	displayFloat(d);
	displayDouble(d);
}

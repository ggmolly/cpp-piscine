/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:34:12 by jallerha          #+#    #+#             */
/*   Updated: 2022/10/04 14:02:56 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	print_upper(char *s)
{
	for (int i = 0; s[i]; i++)
		std::cout << (char)toupper(s[i]);
}

int main(int argc, char **argv)
{
	(void) argv;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; argv[i]; i++)
		print_upper(argv[i]);
	std::cout << std::endl;
}

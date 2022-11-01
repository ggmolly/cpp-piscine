/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:18:19 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/01 23:22:23 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "betterSed.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		print_error("Wrong number of arguments");
		return (1);
	}
	return 0;
}

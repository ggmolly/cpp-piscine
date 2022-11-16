/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:07:13 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/16 16:19:43 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "stdint.h"

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}


int main(void)
{
	Data *test = new Data("Bob", 25);
	uintptr_t serialized = serialize(test);
	Data *deserialized = deserialize(serialized);

	std::cout << *test << std::endl;
	std::cout << serialized << std::endl;
	std::cout << *deserialized << std::endl;

	delete test;
}

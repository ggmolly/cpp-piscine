/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:20:06 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/17 22:07:56 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void iter(T *array, int size, void (*fn)(T const &element))
{
	for (int i = 0; i < size; i++)
		fn(array[i]);
}

template <typename T>
void print(T const &element)
{
	std::cout << element << std::endl;
}

template <typename T>
void squarePrint(T const &element)
{
	std::cout << element * element << std::endl;
}

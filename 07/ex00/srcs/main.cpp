/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:04:47 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/18 13:22:11 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main(void)
{
	std::cout << "=========== INT ===========" << std::endl;
	{
		int a = 2;
		int b = 4;
		std::cout << "a = " << a << " <---> b = " << b << std::endl;
		swap(a, b);
		std::cout << "a = " << a << " <---> b = " << b << std::endl;
		std::cout << "min(a, b) = " << min(a, b) << std::endl;
		std::cout << "max(a, b) = " << max(a, b) << std::endl;
	}
	std::cout << "=========== CHAR ===========" << std::endl;
	{
		char a = 'a';
		char b = 'b';
		std::cout << "a = " << a << " <---> b = " << b << std::endl;
		swap(a, b);
		std::cout << "a = " << a << " <---> b = " << b << std::endl;
		std::cout << "min(a, b) = " << min(a, b) << std::endl;
		std::cout << "max(a, b) = " << max(a, b) << std::endl;
	}
	std::cout << "=========== FLOAT ===========" << std::endl;
	{
		float a = 2.2f;
		float b = 4.4f;
		std::cout << "a = " << a << " <---> b = " << b << std::endl;
		swap(a, b);
		std::cout << "a = " << a << " <---> b = " << b << std::endl;
		std::cout << "min(a, b) = " << min(a, b) << std::endl;
		std::cout << "max(a, b) = " << max(a, b) << std::endl;
	}
	std::cout << "=========== STRING ===========" << std::endl;
	{
		std::string a = "min";
		std::string b = "max";
		std::cout << "a = " << a << " <---> b = " << b << std::endl;
		swap(a, b);
		std::cout << "a = " << a << " <---> b = " << b << std::endl;
		std::cout << "min(a, b) = " << min(a, b) << std::endl;
		std::cout << "max(a, b) = " << max(a, b) << std::endl;
	}
	// std::cout << "=========== INVALID TESTS (SHOULD NOT COMPILE) ===========" << std::endl;
	{
		// int a = 2;
		// float b = 42.42;
		// swap(a, b); // should not compile
		// min(a, b); // should not compile
		// max(a, b); // should not compile
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:27:03 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/18 01:23:15 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

# define DODGERBLUE2 "\033[38;5;27m"
# define HOTPINK1 "\033[38;5;205m"
# define HOTPINK2 "\033[38;5;206m"
# define LIGHTGOLDENROD1 "\033[38;5;227m"
# define LIGHTGOLDENROD2 "\033[38;5;186m"
# define LIGHTSLATEGREY "\033[38;5;103m"
# define MEDIUMSPRINGGREEN "\033[38;5;49m"
# define RED1 "\033[38;5;196m"
# define SPRINGGREEN3 "\033[38;5;47m"
# define RESET "\033[0m"

void fillRandom(Array<int> &arr)
{
	for (unsigned int i = 0; i < arr.size(); i++)
		arr[i] = rand();
}

void tryInit(unsigned int size)
{
	try
	{
		Array<int> arr(size);
	}
	catch(const std::exception& e)
	{
		std::cout << RED1 << "Exception caught : " << e.what() << RESET << std::endl;
	}
}

int main(void)
{
	srand(time(NULL));
	std::cout << "╔═══════════════════════╗" << std::endl;
	std::cout << "║" << DODGERBLUE2 << "     BASIC BEHAVIOR    " << RESET << "║" << std::endl;
    std::cout << "╚═══════════════════════╝" << std::endl;
	{
		Array<int> a(5);
		Array<int> b(5);
		Array<int> c(5);
		std::cout << LIGHTGOLDENROD1 << "Creating array a, b, c of size 5" << RESET << std::endl;
		std::cout << HOTPINK1 << "Size of a: " << a.size() << RESET << std::endl;
		for (size_t i = 0; i < a.size(); i++)
		{
			std::cout << "a[" << i << "] = " << a[i] << std::endl;
		}
		std::cout << MEDIUMSPRINGGREEN << "Copying A to B" << RESET << std::endl;
		b = a;
		std::cout << HOTPINK1 << "Size of b: " << b.size() << RESET << std::endl;
		std::cout << LIGHTGOLDENROD1 << "Filling A randomly" << RESET << std::endl;
		fillRandom(a);
		c = a;
		std::cout << MEDIUMSPRINGGREEN << "Copying A to C" << RESET << std::endl;
		for (size_t i = 0; i < a.size(); i++)
		{
			std::cout << "a[" << i << "] = " << a[i] << std::endl;
		}
		for (size_t i = 0; i < b.size(); i++)
		{
			std::cout << "b[" << i << "] = " << b[i] << std::endl;
		}
		for (size_t i = 0; i < c.size(); i++)
		{
			std::cout << "c[" << i << "] = " << c[i] << std::endl;
		}
	}
	std::cout << "╔═══════════════════════╗" << std::endl;
	std::cout << "║" << RED1 << "     INVALID SIZES     " << RESET << "║" << std::endl;
    std::cout << "╚═══════════════════════╝" << std::endl;
	{
		tryInit(-1);
		tryInit(0);
		tryInit(static_cast<long>(INT_MAX) + 1);
	}
	std::cout << "╔═══════════════════════╗" << std::endl;
	std::cout << "║" << LIGHTGOLDENROD2 << "    INVALID INDEXES    " << RESET << "║" << std::endl;
	std::cout << "╚═══════════════════════╝" << std::endl;
	{
		Array<int> a(5);
		try
		{
			std::cout << "a[5] = " << a[5] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << RED1 << "Exception caught : " << e.what() << RESET << std::endl;
		}
		try
		{
			std::cout << "a[-1] = " << a[-1] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << RED1 << "Exception caught : " << e.what() << RESET << std::endl;
		}
	}
	std::cout << "╔═══════════════════════╗" << std::endl;
	std::cout << "║" << DODGERBLUE2 << "      VALID ARRAY      " << RESET << "║" << std::endl;
	std::cout << "╚═══════════════════════╝" << std::endl;
	{
		std::cout << MEDIUMSPRINGGREEN << "Creating array of size 1" << RESET << std::endl;
		tryInit(1);
		std::cout << MEDIUMSPRINGGREEN << "Creating array of size 100" << RESET << std::endl;
		tryInit(100);
		std::cout << MEDIUMSPRINGGREEN << "Creating array of size 10000" << RESET << std::endl;
		tryInit(10000);
		std::cout << MEDIUMSPRINGGREEN << "Creating array of size 500000" << RESET << std::endl;
		tryInit(500000);
	}
}
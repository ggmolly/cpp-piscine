/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:24:30 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/18 17:53:14 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void tryAdd(Span &span, int n)
{
	try
	{
		span.addNumber(n);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED1 << "Exception caught while adding number : " << e.what() << RESET << std::endl;
	}
}

int main(void)
{
	srand(time(NULL));
    std::cout << "╔══════════════════════╗" << std::endl;
    std::cout << "║" << DODGERBLUE2 << "    BASIC BEHAVIOR    " << RESET << "║" << std::endl;
    std::cout << "╚══════════════════════╝" << std::endl;
	{
		Span span(10);
		std::cout << span << std::endl;
		for (size_t i = 0; i < 10; i++)
			tryAdd(span, i);
		std::cout << span << std::endl;
		tryAdd(span, 0x1337);
		std::cout << span << std::endl;
	}
	std::cout << "╔══════════════════════╗" << std::endl;
    std::cout << "║" << DODGERBLUE2 << "   BASIC BEHAVIOR²    " << RESET << "║" << std::endl;
    std::cout << "╚══════════════════════╝" << std::endl;
	{
		Span span(5);
		std::cout << span << std::endl;
		for (size_t i = 0; i < 5; i++)
		{
			tryAdd(span, i);
			std::cout << span << std::endl;
		}
	}
	std::cout << "╔══════════════════════╗" << std::endl;
    std::cout << "║" << DODGERBLUE2 << "    SUBJECT TEST      " << RESET << "║" << std::endl;
    std::cout << "╚══════════════════════╝" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << MEDIUMSPRINGGREEN << "Shortest span : " << sp.shortestSpan() << RESET << std::endl;
		std::cout << RED1 << "Longest span : " << sp.longestSpan() << RESET << std::endl;
	}
	std::cout << "╔═══════════════════════════════════════╗" << std::endl;
    std::cout << "║" << DODGERBLUE2 << "         SUBJECT TEST (random)         " << RESET << "║" << std::endl;
    std::cout << "╚═══════════════════════════════════════╝" << std::endl;
	{
		Span sp = Span(100000);
		std::cout << sp << std::endl;
		for (size_t i = 0; i < 100000; i++)
		{
			sp.addNumber(rand());
		}
		std::cout << MEDIUMSPRINGGREEN << "Shortest span : " << sp.shortestSpan() << RESET << std::endl;
		std::cout << RED1 << "Longest span : " << sp.longestSpan() << RESET << std::endl;
	}
	std::cout << "╔═══════════════════╗" << std::endl;
    std::cout << "║" << LIGHTGOLDENROD1 << "      Copying      " << RESET << "║" << std::endl;
    std::cout << "╚═══════════════════╝" << std::endl;
	{
		Span originalSpan(3);
		originalSpan.addNumber(-1);
		Span firstCopy = originalSpan;
		firstCopy.addNumber(1);
		Span secondCopy = Span(firstCopy);
		secondCopy.addNumber(2);
		std::cout << originalSpan << std::endl;
		std::cout << firstCopy << std::endl;
		std::cout << secondCopy << std::endl;
	}
	std::cout << "╔════════════════╗" << std::endl;
    std::cout << "║" << LIGHTGOLDENROD1 << "   Range Add    " << RESET << "║" << std::endl;
    std::cout << "╚════════════════╝" << std::endl;
	{
		Span testSpan(30);
		std::vector<int> ten;
		for (size_t i = 0; i < 10; i++)
			ten.push_back(i);
		for (size_t i = 0; i < 4; i++)
		{
			try
			{
				testSpan.addRange(ten.begin(), ten.end());
				std::cout << testSpan << std::endl;
			}
			catch(const std::exception &e)
			{
				std::cout << RED1 << "Exception caught while adding range : " << e.what() << RESET << std::endl;
			}
		}
	}
	return 0;
}

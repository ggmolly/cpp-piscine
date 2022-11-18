/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:29:00 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/18 14:27:06 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"
# include <vector>

# define DODGERBLUE2 "\033[38;5;27m"
# define LIGHTGOLDENROD1 "\033[38;5;227m"
# define MEDIUMSPRINGGREEN "\033[38;5;49m"
# define RED1 "\033[38;5;196m"
# define SPRINGGREEN3 "\033[38;5;47m"
# define RESET "\033[0m"

std::vector<int> createVector(size_t start, size_t end)
{
	std::vector<int> output;
	for (size_t i = start; i < end; i++)
		output.push_back(i);
	return output;
}

void tryFind(std::vector<int> &haystack, int needle)
{
	try
	{
		easyfind(haystack, needle);
		std::cerr << SPRINGGREEN3 << "Found " << needle << " in container!" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED1 << "Caught exception : " << e.what() << RESET << std::endl;
	}
}

int main(void)
{
	std::cout << "╔═════════════════════╗" << std::endl;
    std::cout << "║" << MEDIUMSPRINGGREEN << "        MATCH        " << RESET << "║" << std::endl;
    std::cout << "╚═════════════════════╝" << std::endl;
	{
		std::vector<int> nano = createVector(0, 9);
		std::vector<int> micro = createVector(0, 50);
		std::vector<int> mini = createVector(0, 100);

		tryFind(nano, 5);
		tryFind(micro, 25);
		tryFind(mini, 50);
	}
	std::cout << "╔══════════════════════╗" << std::endl;
    std::cout << "║" << RED1 << "       NO MATCH       " << RESET << "║" << std::endl;
    std::cout << "╚══════════════════════╝" << std::endl;
	{
		std::vector<int> nano = createVector(0, 9);
		std::vector<int> micro = createVector(0, 50);
		std::vector<int> mini = createVector(0, 100);

		tryFind(nano, 10);
		tryFind(micro, 51);
		tryFind(mini, 101);
	}
	std::cout << "╔═══════════════════════╗" << std::endl;
    std::cout << "║" << RED1 << "     EMPTY VECTORS     " << RESET << "║" << std::endl;
    std::cout << "╚═══════════════════════╝" << std::endl;
	{
		std::vector<int> empty;
		tryFind(empty, 5);
	}
	std::cout << "╔═══════════════════════╗" << std::endl;
    std::cout << "║" << LIGHTGOLDENROD1 << "     LARGE VECTORS     " << RESET << "║" << std::endl;
    std::cout << "╚═══════════════════════╝" << std::endl;
	{
		std::vector<int> big = createVector(0, 10000);
		std::vector<int> huge = createVector(0, 25000);
		std::vector<int> gigantic = createVector(0, 100000);

		tryFind(big, 9999);
		tryFind(huge, 24999);
		tryFind(gigantic, 99999);
	}
}

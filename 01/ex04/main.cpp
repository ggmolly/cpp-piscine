/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:18:19 by jallerha          #+#    #+#             */
/*   Updated: 2022/11/02 14:03:34 by jallerha         ###   ########.fr       */
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
	std::ifstream file(argv[1]);
	std::string from = std::string(argv[2]);
	std::string to = std::string(argv[3]);

	if (!file.good() || file.peek() == EOF)
	{
		print_error("Unable to read from file.");
		file.close();
		return (1);
	}

	std::ofstream output(std::string(argv[1]).append(".replace").c_str());

	if (!output.good())
	{
		print_error("Failed to open output file");
		file.close();
		output.close();
		return (1);
	}
	std::string line;
	while (true)
	{
		if (!std::getline(file, line))
		{
			break ;
		}
		str_replace(line, from, to);
		line += "\n";
		if (!output.write(line.c_str(), line.size()))
		{
			print_error("Failed to write to output file. Aborting.");
			break ;
		}
	}
	output.close();
	file.close();
	return (0);
}

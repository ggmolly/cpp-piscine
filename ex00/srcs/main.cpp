/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:09:56 by jallerha          #+#    #+#             */
/*   Updated: 2023/03/14 12:37:16 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <climits>
#include "BitcoinExchange.hpp"

/**
 * @brief Parse the passed input file and prints the result to the standard output
 * 
 * @param path Path to the input file
 * @param exchange Reference to the exchange data
 */
void parseInput(const std::string &path, BitcoinExchange &exchange) {
    std::ifstream inputStream;
    inputStream.open(path.c_str(), std::ios::in);
    if (!inputStream.good())
        throw std::invalid_argument("Unable to open the input file");
    std::string line;
    bool headerParsed;
    // Parse the input file
    while (std::getline(inputStream, line))
    {
        if (!headerParsed)
        {
            // check that we only have two columns (a,b), count the number of commas
            int commaCount = 0;
            while (line.find(" | ") != std::string::npos)
            {
                commaCount++;
                line = line.substr(line.find(" | ") + 1);
            }
            if (commaCount != 1) // we have more than one row
            {
                std::cerr << "Invalid header in the file, exitting." << std::endl;
                return ;
            }
            headerParsed = true;
        } else {
            // Parse a PSV line (' | ')
            std::string date;
            std::string value;

            // Get the date
            date = line.substr(0, line.find(" | "));
            if (!validDate(date))
                std::cerr << "'" << line << "' : invalid date. Skipping." << std::endl;
            value = line.substr(line.find(" | ") + 3);
            // Try to convert the value to a double
            char *err;
            double valueDouble = strtod(value.c_str(), &err);
            if (*err != '\0') // strtod sets `err` to NULL if the conversion was successful
            {
                std::cerr << "Invalid value : '" << line << "' -- Skipping." << std::endl;
                continue ;
            }
            if (valueDouble < 0)
            {
                std::cerr << "Negative value : '" << line << "' -- Skipping." << std::endl;
                continue ;
            }
            if (valueDouble > INT_MAX)
            {
                std::cerr << "Value too high : '" << line << "' -- Skipping." << std::endl;
                continue ;
            }
            try {
                double rate = exchange.getRate(date);
                std::cout << "@ " << date << " " << valueDouble << " BTC = " << rate * valueDouble << " USD" << std::endl;
            } catch (std::invalid_argument &e) {
                std::cerr << "No data for the date '" << date << "'. Skipping." << std::endl;
            }
        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << argv[0] << ": usage: " << argv[0] << " <path_to_input_file>" << std::endl;
        return (1);
    }

    try {
        BitcoinExchange exchange;
        std::string path = argv[1];
        parseInput(path, exchange);
    } catch (std::exception &e) {
        std::cerr << "Unable to load the Bitcoin database : " << e.what() << std::endl;
        return (1);
    }
}

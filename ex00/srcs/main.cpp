/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:09:56 by jallerha          #+#    #+#             */
/*   Updated: 2023/03/14 17:16:36 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <climits>
#include "BitcoinExchange.hpp"

#define GREEN2 "\033[1;32m"
#define RED2 "\033[1;31m"
#define MAGENTA2 "\033[1;35m"
#define RESET "\033[0m"

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
    bool headerParsed = false;
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
            if (valueDouble > 1000)
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
    inputStream.close();
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << argv[0] << ": usage: " << argv[0] << " <path_to_input_file>" << std::endl;
        return (1);
    }

    BitcoinExchange exchange;
    BitcoinExchange exchange2(exchange);
    BitcoinExchange exchange3 = exchange;
}


// Un-comment to test parsing
// int main(void)
// {
//     std::cout << "Testing exchange values parsing" << std::endl;
//     std::cout << "-------------------------------" << std::endl;
    
//     { // Missing date, should throw
//         std::cout << MAGENTA2 << "Missing date : ";
//         try {
//             BitcoinExchange exchange("tests/empty_date.csv");
//             std::cerr << RED2 << "KO!" << RESET << std::endl;
//         } catch (std::exception &e) {
//             std::cerr << GREEN2 << "OK!" << RESET << std::endl;
//         }
//     }

//     { // Invalid date format, should throw
//         std::cout << MAGENTA2 << "Invalid date format : ";
//         try {
//             BitcoinExchange exchange("tests/invalid_date_format.csv");
//             std::cerr << RED2 << "KO!" << RESET << std::endl;
//         } catch (std::exception &e) {
//             std::cerr << GREEN2 << "OK!" << RESET << std::endl;
//         }
//     }

//     { // Invalid month, should throw
//         std::cout << MAGENTA2 << "Invalid month : ";
//         try {
//             BitcoinExchange exchange("tests/invalid_month.csv");
//             std::cerr << RED2 << "KO!" << RESET << std::endl;
//         } catch (std::exception &e) {
//             std::cerr << GREEN2 << "OK!" << RESET << std::endl;
//         }
//     }

//     { // Missing column
//         std::cout << MAGENTA2 << "Missing column : ";
//         try {
//             BitcoinExchange exchange("tests/missing_col.csv");
//             std::cerr << RED2 << "KO!" << RESET << std::endl;
//         } catch (std::exception &e) {
//             std::cerr << GREEN2 << "OK!" << RESET << std::endl;
//         }
//     }

//     { // Missing date
//         std::cout << MAGENTA2 << "Missing date : ";
//         try {
//             BitcoinExchange exchange("tests/no_date.csv");
//             std::cerr << RED2 << "KO!" << RESET << std::endl;
//         } catch (std::exception &e) {
//             std::cerr << GREEN2 << "OK!" << RESET << std::endl;
//         }
//     }

//     { // No read permissions
//         std::cout << MAGENTA2 << "No read permissions : ";
//         try {
//             BitcoinExchange exchange("tests/no_read.csv");
//             std::cerr << RED2 << "KO!" << RESET << std::endl;
//         } catch (std::exception &e) {
//             std::cerr << GREEN2 << "OK!" << RESET << std::endl;
//         }
//     }

//     { // Missing value
//         std::cout << MAGENTA2 << "Missing value : ";
//         try {
//             BitcoinExchange exchange("tests/no_val.csv");
//             std::cerr << RED2 << "KO!" << RESET << std::endl;
//         } catch (std::exception &e) {
//             std::cerr << GREEN2 << "OK!" << RESET << std::endl;
//         }
//     }

//     { // Valid file
//         std::cout << MAGENTA2 << "Valid file : ";
//         try {
//             BitcoinExchange exchange("tests/valid_data.csv");
//             std::cerr << GREEN2 << "OK!" << RESET << std::endl;
//         } catch (std::exception &e) {
//             std::cerr << RED2 << "KO!" << RESET << std::endl;
//         }
//     }

//     { // Non-existant file
//         std::cout << MAGENTA2 << "Non-existant file : ";
//         try {
//             BitcoinExchange exchange("tests/does_not_exist.csv");
//             std::cerr << RED2 << "KO!" << RESET << std::endl;
//         } catch (std::exception &e) {
//             std::cerr << GREEN2 << "OK!" << RESET << std::endl;
//         }
//     }
// }

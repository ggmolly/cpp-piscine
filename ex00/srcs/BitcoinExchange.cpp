/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:09:54 by jallerha          #+#    #+#             */
/*   Updated: 2023/03/14 11:58:05 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange()
{
    this->_db_path = "data.csv";
    // std::cerr << "BitcoinExchange default constructor called" << std::endl;
    this->_parse();
}

BitcoinExchange::BitcoinExchange(const std::string &db_path)
{
    this->_db_path = db_path;
    // std::cerr << "BitcoinExchange custom constructor called, path : " << this->_db_path << std::endl;
    this->_parse();
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &rhs)
{
    if (this != &rhs)
    {
        this->_db_path = rhs._db_path;
        this->_db = rhs._db;
    }
    return *this;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &src)
{
    // std::cerr << "BitcoinExchange copy constructor called" << std::endl;
    *this = src;
}

BitcoinExchange::~BitcoinExchange()
{
    // std::cerr << "BitcoinExchange destructor called" << std::endl;
}

/**
 * @brief Parse the passed database, checks the format properly, returns false if anything went wrong
*/
bool BitcoinExchange::_parse()
{
    std::ifstream fileStream;
    fileStream.open(this->_db_path.c_str(), std::ios::in);
    if (!fileStream.good())
        throw std::runtime_error("Could not open file");
    // check if the file is opened, and readable
    bool headerParsed = false; // csv contains a header, so we'll just skip it
    std::string line;

    // Read each line
    while (std::getline(fileStream, line))
    {
        if (!headerParsed)
        {
            // check that we only have two columns (a,b), count the number of commas
            int commaCount = 0;
            while (line.find(",") != std::string::npos)
            {
                commaCount++;
                line = line.substr(line.find(",") + 1);
            }
            if (commaCount != 1) // we have more than one row
                throw std::invalid_argument("Invalid CSV header");
            headerParsed = true;
        } else {
            // Parse a CSV line
            std::string date;
            std::string value;

            // Get the date
            date = line.substr(0, line.find(","));
            value = line.substr(line.find(",") + 1);

            // Try to convert the value to a double
            char *err;
            double valueDouble = strtod(value.c_str(), &err);
            if (*err != '\0') // strtod sets `err` to NULL if the conversion was successful
            {
                std::cerr << "[INFO] Failed to parse line '" << line << "' : invalid CSV row, ignoring." << std::endl;
                throw std::invalid_argument("Invalid CSV row");
            }
            // if the parsing was successful, add the value to the map
            this->_db[date] = valueDouble;
        }
    }
    return true;
}

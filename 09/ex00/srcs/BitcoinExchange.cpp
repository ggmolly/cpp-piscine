/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:09:54 by jallerha          #+#    #+#             */
/*   Updated: 2023/03/14 17:19:02 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

/**
 * @brief Custom atoul that parses a string to an unsigned int
 * 
 * @param data The string to parse as unsigned int
 * @return unsigned int The parsed unsigned int
 * 
 * @throws std::runtime_error if any error occcurs
 */
unsigned int atoul(const std::string &data) {
    unsigned int val = 0;
    if (data.find("-") != std::string::npos)
        throw std::runtime_error("Negative number are not allowed");
    for (size_t i = 0; i < data.size(); i++) {
        if (!isdigit(data[i]))
            throw std::runtime_error("Non-digit character found");
        val = val * 10 + (data[i] - '0');
    }
    return val;
}

bool validDate(const std::string &date) {
    // Date must be in yyyy-mm-dd format
    if (date.length() != 10) // Quick check to simplify parsing afterwards
        return false;
    if (date[4] != '-' || date[7] != '-') // Same
        return false;
    try {
        unsigned int year = atoul(date.substr(0, 4)); // Year
        unsigned int month = atoul(date.substr(5, 2)); // Month
        unsigned int day = atoul(date.substr(8, 2)); // Day

        // Check range
        if (!(year > 0 && year <= 9999)) // yyyy (so 4 digits)
            return false;
        if (!(month > 0 && month < 13)) // mm (between 1 and 12)
            return false;
        if (!(day > 0 && day < 32)) // dd (between 1 and 31)
            return false;
    } catch (std::runtime_error &e) {
        return false;
    }
    return true;
}

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
        _parse();
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
            {
                fileStream.close();
                throw std::invalid_argument("Invalid CSV header");
            }
            headerParsed = true;
        } else {
            // Parse a CSV line
            std::string date;
            std::string value;

            // Get the date
            date = line.substr(0, line.find(","));
            if (!validDate(date))
            {
                fileStream.close();
                throw std::invalid_argument("Invalid date found");
            }
            value = line.substr(line.find(",") + 1);
            if (value.size() == 0)
            {
                fileStream.close();
                throw std::invalid_argument("Invalid CSV row");
            }

            // Try to convert the value to a double
            char *err;
            double valueDouble = strtod(value.c_str(), &err);
            if (*err != '\0') // strtod sets `err` to NULL if the conversion was successful
            {
                fileStream.close();
                throw std::invalid_argument("Invalid CSV row");
            }
            // if the parsing was successful, add the value to the map
            this->_db[date] = valueDouble;
        }
    }
    fileStream.close();
    return true;
}

/**
 * @brief Get the rate for a given date
 * 
 * @throws std::invalid_argument if the date is not found
 * @param date The date in yyyy-mm-dd format
 * @return double The rate for the given date
 */
double BitcoinExchange::getRate(std::string &date)
{
    std::map<std::string, double>::iterator it = this->_db.find(date);
    if (it == this->_db.end())
        throw std::invalid_argument("Date not found");
    return it->second;
}

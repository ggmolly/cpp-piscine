/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:09:55 by jallerha          #+#    #+#             */
/*   Updated: 2023/03/14 12:33:38 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <map>
#include <cstdlib>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string &db_path);
        BitcoinExchange &operator=(BitcoinExchange &ref);
        BitcoinExchange(BitcoinExchange &src);
        ~BitcoinExchange();
        double getRate(std::string &date);
    private:
        std::string _db_path;
        std::map<std::string, double> _db;
        bool _parse();
};

unsigned int atoul(const std::string &data);
bool validDate(const std::string &date);

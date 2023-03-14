/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:09:55 by jallerha          #+#    #+#             */
/*   Updated: 2023/03/14 11:41:57 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <map>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string &db_path);
        BitcoinExchange &operator=(BitcoinExchange &ref);
        BitcoinExchange(BitcoinExchange &src);
        ~BitcoinExchange();
        double getRate(const std::string &date);
    private:
        std::string _db_path;
        std::map<std::string, double> _db;
        bool _parse();
};

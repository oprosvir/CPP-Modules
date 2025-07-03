/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:10:49 by oprosvir          #+#    #+#             */
/*   Updated: 2025/07/03 01:59:03 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <sstream>
#include <cstdlib>
#include <iomanip>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : _rates(other._rates) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        _rates = other._rates;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& dbFilename) {
    std::ifstream file(dbFilename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database file.");
    
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date, rateStr;
        if (!std::getline(iss, date, ',') || !std::getline(iss, rateStr))
           continue;
           
        date = trim(date);
        rateStr = trim(rateStr);
        float rate = std::atof(rateStr.c_str());
        
        // std::cout << std::fixed << std::setprecision(2)
        //   << "[DEBUG] Parsed date = " << date 
        //   << ", rate = " << rate << std::endl;

        _rates[date] = rate;
    }
}

std::string BitcoinExchange::trim(const std::string& str) const {
    size_t first = str.find_first_not_of(" \t\r\n");
    size_t last = str.find_last_not_of(" \t\r\n");
    if (first == std::string::npos || last == std::string::npos)
        return "";
    return str.substr(first, last - first + 1);
}
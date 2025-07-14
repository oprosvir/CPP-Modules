/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:10:49 by oprosvir          #+#    #+#             */
/*   Updated: 2025/07/15 00:45:02 by oprosvir         ###   ########.fr       */
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

std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    size_t last = str.find_last_not_of(" \t\r\n");
    if (first == std::string::npos || last == std::string::npos)
        return "";
    return str.substr(first, last - first + 1);
}

// float or a positive integer, between 0 and 1000
bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value) const {
    std::istringstream iss(valueStr);
    if (!(iss >> value) || !iss.eof()) {
        std::cerr << "Error: invalid value => " << valueStr << std::endl;
        return false;
    }
    
    if (value < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    
    if (value > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

static bool isLeapYear(int year) {
    return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

// YYYY-MM-DD format
bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    for (size_t i = 0; i < date.size(); ++i) {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }

    int y = std::atoi(date.substr(0, 4).c_str()); //year
    int m = std::atoi(date.substr(5, 2).c_str()); //month
    int d = std::atoi(date.substr(8, 2).c_str()); //day

    if (m < 1 || m > 12 || d < 1 || d > 31)
        return false;
    
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
        return false;

    if (m == 2) {
        if (d > 29)
            return false;
        if (d == 29 && !isLeapYear(y))
            return false;
    }
    // std::cout << "[DEBUG] Valid date: " << date << std::endl;    
    return true;
}

void BitcoinExchange::processLine(const std::string& line) const {
    std::istringstream iss(line);
    std::string date, valueStr;

    std::getline(iss, date, '|');
    std::getline(iss, valueStr);
    
    date = trim(date); 
    valueStr = trim(valueStr);
    if (date.empty() || valueStr.empty()) {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }

    if (!isValidDate(date)) {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }

    if (date < _rates.begin()->first) {
        std::cerr << "Error: no rate available before " << _rates.begin()->first << std::endl;
        return;
    }
    
    float value;
    if (!isValidValue(valueStr, value))
        return;
    
    std::map<std::string, float>::const_iterator it = _rates.lower_bound(date);
    if (it == _rates.end() || it->first != date)
        --it;
    
    float result = value * it->second;
    std::cout << date << " => " << valueStr << " = " 
              << std::fixed << std::setprecision(2)
              << result << std::endl;
}
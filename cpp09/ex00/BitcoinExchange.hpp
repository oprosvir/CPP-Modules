/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:10:56 by oprosvir          #+#    #+#             */
/*   Updated: 2025/07/14 23:37:38 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>

class BitcoinExchange {
private:
	std::map<std::string, float> _rates; // key: date, value: rate
	
	bool isValidValue(const std::string& valueStr, float& value) const;
	bool isValidDate(const std::string& date) const;
	
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other); 
	~BitcoinExchange();

	BitcoinExchange(const std::string& dbFilename); // load CSV database
	void processLine(const std::string& line) const;
};

std::string trim(const std::string& str);

#endif
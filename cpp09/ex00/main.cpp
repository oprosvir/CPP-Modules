/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:10:14 by oprosvir          #+#    #+#             */
/*   Updated: 2025/07/03 01:24:17 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    
    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    
    try {
        BitcoinExchange exchange("data.csv");
        std::string line;
        std::getline(inputFile, line);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
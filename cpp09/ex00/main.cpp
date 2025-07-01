/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:10:14 by oprosvir          #+#    #+#             */
/*   Updated: 2025/07/01 21:04:29 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2)
        return (std::cout << "Error: Usage: " << argv[0] << " <filepath>" << std::endl, 1);
        
    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) 
        return (std::cerr << "Error: could not open file." << std::endl, 1);
    
    return 0;
}
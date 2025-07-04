/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 00:41:18 by oprosvir          #+#    #+#             */
/*   Updated: 2025/07/04 17:39:21 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "Error: Wrong number of arguments." << std::endl;
        return 1;
    }
    
    std::string input = argv[1];
    if (input.empty()) {
        std::cerr << "Error: Empty input." << std::endl;
        return 1;
    }

    try {
        int result = RPN::evaluate(input);
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 09:05:27 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/11 17:29:28 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./harlFilter <level>" << std::endl;
        return 1;
    }
    
    std::string level = argv[1];
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int index = -1;
    
    for (int i = 0; i < 4; ++i) {
        if (level == levels[i]) {
            index = i;
            break;
        }
    }

    Harl harl;

    switch (index) {
        case 0:
            harl.complain("DEBUG");
            // fall through
        case 1:
            harl.complain("INFO");
            // fall through
        case 2:
            harl.complain("WARNING");
            // fall through
        case 3:
            harl.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
    
    return 0;
}
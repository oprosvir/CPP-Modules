/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:18:48 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/07 00:31:09 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {
    PhoneBook phoneBook;
    std::string command;
    
    std::cout << "Welcome to the PhoneBook!" << std::endl;
    
    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (std::cin.eof()) {
            std::cout << "\nGoodbye!" << std::endl;
            break;
        }
        
        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else if (command == "EXIT") {
            std::cout << "Exiting PhoneBook..." << std::endl;
            break;
        } else
            std::cout << "Invalid command. Please try again." << std::endl;
    }
    
    return 0;
}
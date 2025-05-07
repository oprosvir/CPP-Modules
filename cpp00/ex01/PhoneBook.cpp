/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:17:24 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/07 12:46:34 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static std::string truncate(std::string str);
static bool safeGetline(std::string& input, const std::string& prompt);

// constructor with initialization list
PhoneBook::PhoneBook() : _index(0), _count(0) {}

void PhoneBook::addContact() {
    Contact newContact;
    std::string input;

    if (!safeGetline(input, "Enter first name: ")) return;
    newContact.setFirstName(input);
    
    if (!safeGetline(input, "Enter last name: ")) return;
    newContact.setLastName(input);
    
    if (!safeGetline(input, "Enter nickname: ")) return;
    newContact.setNickname(input);

    if (!safeGetline(input, "Enter phone number: ")) return;  
    newContact.setPhoneNumber(input);
    
    if (!safeGetline(input, "Enter darkest secret: ")) return;
    newContact.setDarkestSecret(input);

    _contacts[_index] = newContact;
    _index = (_index + 1) % 8;
    if (_count < 8) _count++;
    
    std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::searchContact() const {
    if (_count == 0) {
        std::cout << "PhoneBook is empty." << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index"       << "|"
              << std::setw(10) << "First Name"  << "|"
              << std::setw(10) << "Last Name"   << "|"
              << std::setw(10) << "Nickname"    << std::endl;

    for (int i = 0; i < _count; ++i) {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncate(_contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncate(_contacts[i].getLastName())  << "|"
                  << std::setw(10) << truncate(_contacts[i].getNickname())  << std::endl;
    }

    int index;
    std::cout << "Enter index to view full contact: ";
    std::cin >> index; // if input not int/too big, failbit is set

    if (std::cin.fail() || index < 0 || index >= _count) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid index!" << std::endl;
        return;
    }

    const Contact& c = _contacts[index];
    std::cout << "First name: "     << c.getFirstName()     << std::endl;
    std::cout << "Last name: "      << c.getLastName()      << std::endl;
    std::cout << "Nickname: "       << c.getNickname()      << std::endl;
    std::cout << "Phone number: "   << c.getPhoneNumber()   << std::endl;
    std::cout << "Darkest secret: " << c.getDarkestSecret() << std::endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

static std::string truncate(std::string str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

// `input` ref to write directly into the original variable
// `prompt` ref to avoid unnecessary string copy
static bool safeGetline(std::string& input, const std::string& prompt) {
    std::cout << prompt;
    std::getline(std::cin, input);
    if (input.empty()) return false;
    if (input.length() > 1024) {
        std::cout << "Input too long!" << std::endl;
        return false;
    }
    return true;
}

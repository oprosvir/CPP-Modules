/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:22:44 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/06 23:31:45 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// --- SETTERS ---

void Contact::setFirstName(std::string firstName) {
    _firstName = firstName;
}

void Contact::setLastName(std::string lastName) {
	_lastName = lastName;
}

void Contact::setNickname(std::string nickname) {
	_nickname = nickname;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
	_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret) {
	_darkestSecret = darkestSecret;
}

// --- GETTERS ---

std::string Contact::getFirstName() const {
    return _firstName;
}

std::string Contact::getLastName() const {
    return _lastName;
}

std::string Contact::getNickname() const {
    return _nickname;
}

std::string Contact::getPhoneNumber() const {
    return _phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return _darkestSecret;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:21:17 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/07 12:09:30 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <limits>
#include <iomanip>

class PhoneBook {
private:
	Contact _contacts[8];
	int		_index;
	int		_count;
public:
	PhoneBook();
	void addContact();
	void searchContact() const;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 01:22:12 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/23 01:28:58 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
    // std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other) {
    // std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
    // std::cout << "Ice assignment operator called" << std::endl;
    (void)other;
    return *this;
}

Ice::~Ice() {
    // std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

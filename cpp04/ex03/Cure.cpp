/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 01:22:49 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/23 01:29:24 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
    // std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {
    // std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
    // std::cout << "Cure assignment operator called" << std::endl;
    (void)other;
    return *this;
}

Cure::~Cure() {
    // std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

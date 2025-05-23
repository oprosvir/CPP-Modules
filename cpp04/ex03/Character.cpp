/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 01:23:31 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/23 02:24:22 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("Unnamed") {
    // std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        _inventory[i] = NULL;
}

Character::Character(std::string const & name) : _name(name) {
    // std::cout << "Character constructor called for " << name << std::endl;
    for (int i = 0; i < 4; ++i)
        _inventory[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name) {
    // std::cout << "Character copy constructor called" << std::endl;
    for (int i = 0; i < 4; ++i) {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone(); // deep copy
        else
            _inventory[i] = NULL;
    }        
}

Character& Character::operator=(const Character& other) {
    // std::cout << "Character assignment operator called" << std::endl;
    if (this != &other) {
        _name = other._name;
        for (int i = 0; i < 4; ++i) {
            if (_inventory[i]) {
                delete _inventory[i];
                _inventory[i] = NULL;
            }
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
        }
    }
    return *this;
}

Character::~Character() {
    // std::cout << "Character destructor called for " << _name << std::endl;
    for (int i = 0; i < 4; ++i) {
        if (_inventory[i])
            delete _inventory[i];
    }
}

std::string const & Character::getName() const {
    return _name;
}

void Character::equip(AMateria* m) {
    if (!m)
        return;
    for (int i = 0; i < 4; ++i) {
        if (_inventory[i] == NULL) {
            _inventory[i] = m;
            std::cout << _name << " equipped materia "
            << m->getType() << " in slot " << i << std::endl;
            return;
        }
    }
    std::cout << "Inventory full. Could not equip." << std::endl;
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && _inventory[idx]) {
        std::cout << _name << " unequipped " << _inventory[idx]->getType()
        << " materia from slot " << idx << std::endl;
        _inventory[idx] = NULL; //  not delete
    } else {
        std::cout << "Cannot unequip: invalid index or empty slot" << std::endl;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && _inventory[idx]) {
        _inventory[idx]->use(target);
    } else {
        std::cout << "Cannot use materia: invalid index or empty slot" << std::endl;
    }
}

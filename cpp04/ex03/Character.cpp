/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 01:23:31 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/23 10:09:33 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("Unnamed"), _dropCount(0) {
    for (int i = 0; i < 4; ++i)
        _inventory[i] = NULL;
    for (int i = 0; i < 42; ++i)
        _dropped[i] = NULL;
}

Character::Character(std::string const & name) : _name(name), _dropCount(0) {
    for (int i = 0; i < 4; ++i)
        _inventory[i] = NULL;
    for (int i = 0; i < 42; ++i)
        _dropped[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name), _dropCount(0) {
    for (int i = 0; i < 4; ++i) {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
    for (int i = 0; i < 42; ++i)
        _dropped[i] = NULL;
}


Character& Character::operator=(const Character& other) {
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

        for (int i = 0; i < _dropCount; ++i) {
            if (_dropped[i])
                delete _dropped[i];
            _dropped[i] = NULL;
        }
        _dropCount = 0;
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; ++i)
        if (_inventory[i])
            delete _inventory[i];

    for (int i = 0; i < _dropCount; ++i)
        if (_dropped[i])
            delete _dropped[i];
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
    std::cout << _name << "'s inventory full. Discarding materia: " << m->getType() << std::endl;
    delete m;
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && _inventory[idx]) {
        std::cout << _name << " unequipped " << _inventory[idx]->getType()
                  << " materia from slot " << idx << std::endl;
        if (_dropCount < 42) {
            _dropped[_dropCount++] = _inventory[idx];
        } else {
            std::cout << "Drop buffer full. Deleting materia." << std::endl;
            delete _inventory[idx];
        }
        _inventory[idx] = NULL;
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

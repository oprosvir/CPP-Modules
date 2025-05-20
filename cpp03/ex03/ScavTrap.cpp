/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:41:03 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/20 23:40:23 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    _maxHitPoints = 100;
    std::cout << "ScavTrap default constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    _maxHitPoints = 100;
    std::cout << "ScavTrap named constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called for " << other._name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "ScavTrap assignment operator called for " << _name << std::endl;
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called for " << _name << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (_hitPoints <= 0 || _energyPoints <= 0) {
        std::cout << "ScavTrap " << _name << " can't attack. No HP or energy." << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ScavTrap " << _name << " launches a savage attack on " << target
              << ", dealing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const ScavTrap& scav) {
    os << "ScavTrap [" << scav.getName() << "]"
       << " HP: " << scav.getHitPoints()
       << ", Energy: " << scav.getEnergyPoints()
       << ", Attack: " << scav.getAttackDamage();
    return os;
}



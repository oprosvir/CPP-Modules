/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 00:22:41 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/20 16:54:19 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _name("Dummy"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap default constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap named constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : _name(other._name), _hitPoints(other._hitPoints),
      _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
    std::cout << "ClapTrap copy constructor called for " << _name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        std::cout << "Assigning from " << other._name << " to " << _name << std::endl;
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called for " << _name << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (_hitPoints <= 0 || _energyPoints <= 0) {
        std::cout << "ClapTrap " << _name << " can't attack. No HP or energy." << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if ((int)amount < 0 || amount > 1000) {
        std::cout << "ClapTrap " << _name << " received invalid damage amount. Damage skipped." << std::endl;
        return;
    }
    _hitPoints -= amount;
    if (_hitPoints < 0) _hitPoints = 0;
    std::cout << "ClapTrap " << _name << " takes " << amount
              << " points of damage! Current HP: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if ((int)amount < 0 || amount > 1000) {
        std::cout << "ClapTrap " << _name << " received invalid repair amount. Repair skipped." << std::endl;
        return;
    }
    if (_hitPoints <= 0 || _energyPoints <= 0) {
        std::cout << "ClapTrap " << _name << " can't repair. No HP or energy." << std::endl;
        return;
    }
    if (_hitPoints == 10) {
        std::cout << "ClapTrap " << _name << " is already at full HP. Repair skipped." << std::endl;
        return;
    }
    _energyPoints--;
    _hitPoints += amount;
    if (_hitPoints > 10)
		_hitPoints = 10;
    std::cout << "ClapTrap " << _name << " repairs itself for "
              << amount << " hit points! Current HP: " << _hitPoints << std::endl;
}

std::string ClapTrap::getName() const { return _name; }
int ClapTrap::getHitPoints() const { return _hitPoints; }
int ClapTrap::getEnergyPoints() const { return _energyPoints; }
int ClapTrap::getAttackDamage() const { return _attackDamage; }

std::ostream& operator<<(std::ostream& os, const ClapTrap& clap) {
    os << "ClapTrap [" << clap.getName() << "]"
       << " HP: " << clap.getHitPoints()
       << ", Energy: " << clap.getEnergyPoints()
       << ", Attack: " << clap.getAttackDamage();
    return os;
}

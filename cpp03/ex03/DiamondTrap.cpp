/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:40:19 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/21 00:28:02 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
    _name = "Dummy";
    ClapTrap::_name = _name + "_clap_name";
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
    _maxHitPoints = FragTrap::_maxHitPoints;

    std::cout << "DiamondTrap default constructor called for " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
    _name = name;
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
    _maxHitPoints = FragTrap::_maxHitPoints;

    std::cout << "DiamondTrap named constructor called for " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), FragTrap(other), ScavTrap(other) {
    _name = other._name;
    std::cout << "DiamondTrap copy constructor called for " << _name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        _name = other._name;
    }
    std::cout << "DiamondTrap assignment operator called for " << _name << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called for " << _name << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "My name is " << _name << std::endl;
    std::cout << "My ClapTrap name is " << ClapTrap::_name << std::endl;
}

std::ostream& operator<<(std::ostream& os, const DiamondTrap& d) {
    os << "DiamondTrap [" << d.getName() << "]"
       << " HP: " << d.getHitPoints()
       << ", Energy: " << d.getEnergyPoints()
       << ", Attack: " << d.getAttackDamage();
    return os;
}
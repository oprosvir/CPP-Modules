/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:41:37 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/20 23:40:14 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    _maxHitPoints = 100;
    std::cout << "FragTrap default constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    _maxHitPoints = 100;
    std::cout << "FragTrap named constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called for " << other._name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "FragTrap assignment operator called for " << _name << std::endl;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called for " << _name << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name << " wants a high five!" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const FragTrap& frag) {
    os << "FragTrap [" << frag.getName() << "]"
       << " HP: " << frag.getHitPoints()
       << ", Energy: " << frag.getEnergyPoints()
       << ", Attack: " << frag.getAttackDamage();
    return os;
}
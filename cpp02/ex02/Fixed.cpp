/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:26:11 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/16 17:55:00 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    // std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed(const int val) {
    // std::cout << "Int constructor called" << std::endl;
    _rawBits = val << _fractionalBits;
}

Fixed::Fixed(const float val) {
    // std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(val * (1 << _fractionalBits));
}

Fixed& Fixed::operator=(const Fixed& other) {
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _rawBits = other._rawBits;
    return *this;
}

int Fixed::getRawBits(void) const {
    return _rawBits;
}

void Fixed::setRawBits(int const raw) {
    _rawBits = raw;
}

int Fixed::toInt(void) const {
    return _rawBits >> _fractionalBits;
}

float Fixed::toFloat(void) const {
    return (float)_rawBits / (1 << _fractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed& other) const { return _rawBits > other._rawBits; }
bool Fixed::operator<(const Fixed& other) const { return _rawBits < other._rawBits; }
bool Fixed::operator>=(const Fixed& other) const { return _rawBits >= other._rawBits; }
bool Fixed::operator<=(const Fixed& other) const { return _rawBits <= other._rawBits; }
bool Fixed::operator==(const Fixed& other) const { return _rawBits == other._rawBits; }
bool Fixed::operator!=(const Fixed& other) const { return _rawBits != other._rawBits; }

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other.toFloat() == 0.0f) {
        std::cerr << "Warning: division by zero!" << std::endl;
        return Fixed(0);
    }
    return Fixed(this->toFloat() / other.toFloat());
}

// prefix ++a
Fixed& Fixed::operator++() {
    _rawBits++;
    return *this;
}

// postfix a++
Fixed Fixed::operator++(int) {
    Fixed tmp = *this;
    _rawBits++;
    return tmp;
}

// prefix --a
Fixed& Fixed::operator--() {
    _rawBits--;
    return *this;
}

// postfix a--
Fixed Fixed::operator--(int) {
    Fixed tmp = *this;
    _rawBits--;
    return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 00:55:21 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/22 20:38:34 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    _type = "Cat";
    _brain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
    _brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        _type = other._type;
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}

Cat::~Cat() {
    delete _brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow! 🐱" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea) {
    _brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    return _brain->getIdea(index);
}

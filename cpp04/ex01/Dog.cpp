/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 00:54:35 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/21 01:05:21 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
    brain = new Brain(*other.brain); // глубокая копия
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;

        // удалить старый мозг
        delete brain;
        // глубокая копия
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof! 🐶" << std::endl;
}

void Dog::setIdea(int index, const std::string& idea) {
    brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
    return brain->getIdea(index);
}


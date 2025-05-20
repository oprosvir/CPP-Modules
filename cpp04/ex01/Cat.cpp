/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 00:55:21 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/21 01:06:24 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
    brain = new Brain(*other.brain); // глубокая копия
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;

        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow! 🐱" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea) {
    brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    return brain->getIdea(index);
}

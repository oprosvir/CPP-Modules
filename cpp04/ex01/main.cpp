/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 01:06:50 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/21 01:07:02 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "\n=== Creating Animals Array ===" << std::endl;
    const int size = 10;
    Animal* animals[size];

    // Первые 5 — Dog, остальные — Cat
    for (int i = 0; i < size / 2; ++i)
        animals[i] = new Dog();
    for (int i = size / 2; i < size; ++i)
        animals[i] = new Cat();

    std::cout << "\n=== Deleting Animals Array ===" << std::endl;
    for (int i = 0; i < size; ++i)
        delete animals[i];

    std::cout << "\n=== Deep Copy Test ===" << std::endl;
    Dog original;
    original.setIdea(0, "Chase the cat");
    original.setIdea(1, "Bark at the mailman");

    Dog copy = original; // вызывает копирующий конструктор
    copy.setIdea(0, "Nap on the sofa");

    std::cout << "Original idea[0]: " << original.getIdea(0) << std::endl;
    std::cout << "Copy idea[0]:     " << copy.getIdea(0) << std::endl;

    return 0;
}

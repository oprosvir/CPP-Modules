/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 00:46:42 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/21 00:57:20 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "\n=== Correct polymorphism ===" << std::endl;

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    i->makeSound(); // Meow
    j->makeSound(); // Woof
    meta->makeSound(); // generic

    delete meta;
    delete j;
    delete i;

    std::cout << "\n=== Wrong polymorphism ===" << std::endl;

    const WrongAnimal* wrong = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << std::endl;
    wrongCat->makeSound(); // ❌ выведет звук WrongAnimal, а не WrongCat
    wrong->makeSound();

    delete wrongCat;
    delete wrong;

    return 0;
}

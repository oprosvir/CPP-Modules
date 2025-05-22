/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 01:06:50 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/22 22:08:45 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main(void) {
    std::cout << "\n\033[1;34m=== Valid Polymorphic Calls ===\033[0m" << std::endl;
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << dog->getType() << " ";
    dog->makeSound();

    std::cout << cat->getType() << " ";
    cat->makeSound();

    delete dog;
    delete cat;

    std::cout << "\n\033[1;34m=== Deep Copy Test ===\033[0m" << std::endl;

    Dog dog1;
    dog1.setIdea(0, "Bark at shadows");

    Dog dog2(dog1);
    dog1.setIdea(0, "Nap under the sun");

    std::cout << "dog1 idea[0]: " << dog1.getIdea(0) << std::endl;
    std::cout << "dog2 idea[0]: " << dog2.getIdea(0) << std::endl;

    std::cout << "\n\033[1;34m=== Array of Animals ===\033[0m" << std::endl;
    
    Animal* animals[4];

    for (int i = 0; i < 2; ++i)
        animals[i] = new Dog();
    for (int i = 2; i < 4; ++i)
        animals[i] = new Cat();

    for (int i = 0; i < 4; ++i)
        animals[i]->makeSound();

    for (int i = 0; i < 4; ++i)
        delete animals[i];

    std::cout << "\n\033[1;31m=== Invalid (commented out) ===\033[0m" << std::endl;

    // const Animal* meta = new Animal();
    // Animal a;

    std::cout << "\n\033[1;34m=== Destructors ===\033[0m" << std::endl;
    
    return 0;    
}


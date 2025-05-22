/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 01:06:50 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/22 21:55:53 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main(void) {
    std::cout << "\n\033[1;34m=== Creating Animals Array ===\033[0m" << std::endl;
    Animal* animals[10];

    for (int i = 0; i < 5; ++i)
        animals[i] = new Dog();
    for (int i = 5; i < 10; ++i)
        animals[i] = new Cat();

    std::cout << "\n\033[1;34m=== Deleting Animals Array ===\033[0m" << std::endl;
    for (int i = 0; i < 10; ++i)
        delete animals[i];

    std::cout << "\n\033[1;34m=== Deep Copy Test ===\033[0m" << std::endl;
    Dog original;
    original.setIdea(0, "Chase the cat");
    original.setIdea(1, "Bark at the mailman");

    Dog copy(original);
    copy.setIdea(0, "Nap on the sofa");  // change in copy
    original.setIdea(2, "Roll in the grass");    // add in original

    std::cout << "Original idea[0]: " << original.getIdea(0) << std::endl;
    std::cout << "Original idea[1]: " << original.getIdea(1) << std::endl;
    std::cout << "Original idea[2]: " << original.getIdea(2) << std::endl;
    std::cout << "Copy idea[0]:     " << copy.getIdea(0) << std::endl;
    std::cout << "Copy idea[1]:     " << copy.getIdea(1) << std::endl;
    std::cout << "Copy idea[2]:     " << copy.getIdea(2) << std::endl;

    std::cout << "\n\033[1;34m=== Assignment Operator Test ===\033[0m" << std::endl;
    Cat cat;
    cat.setIdea(0, "Scratch the sofa");

    Cat cat1;
    cat.setIdea(0, "Sleep in the sun");
    cat1 = cat; // operator=

    cat.setIdea(0, "Knock over a glass");

    std::cout << "Cat idea[0]: " << cat.getIdea(0) << std::endl;
    std::cout << "Cat1 idea[0]: " << cat1.getIdea(0) << std::endl;
    
    std::cout << "\n\033[1;34m=== Basic Leak Check from Subject ===\033[0m" << std::endl;

    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j; // should not create a leak
    delete i;

    std::cout << "\n\033[1;34m=== Destructors ===\033[0m" << std::endl;

    return 0;
}

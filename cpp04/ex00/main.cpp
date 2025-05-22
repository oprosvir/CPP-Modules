/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 00:46:42 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/22 21:56:14 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void) {
    std::cout << "\n\033[1;34m=== Correct polymorphism ===\033[0m" << std::endl;

    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;
    cat->makeSound();  // Cat::makeSound()
    dog->makeSound();  // Dog::makeSound()
    meta->makeSound(); // Animal::makeSound()

    delete meta;
    delete dog;
    delete cat;

    std::cout << "\n\033[1;34m=== Wrong polymorphism (no virtual) ===\033[0m" << std::endl;

    const WrongAnimal* wrongCat = new WrongCat();
    wrongCat->makeSound(); // WrongAnimal::makeSound()
    
    delete wrongCat;

    std::cout << "\n\033[1;34m=== Copy constructor test ===\033[0m" << std::endl;
    
    Dog originalDog;
    Dog copyDog(originalDog);

    Cat originalCat;
    Cat copyCat(originalCat);

    std::cout << "\n\033[1;34m=== Assignment operator test ===\033[0m" << std::endl;
    
    Dog dog1;
    Dog dog2;
    dog2 = dog1;

    Cat cat1;
    Cat cat2;
    cat2 = cat1;

    std::cout << "\n\033[1;34m=== Assignment via pointers ===\033[0m" << std::endl;

    Cat* catt = new Cat();
    Cat* cattt = new Cat();
    Dog* dogg = new Dog();
    *catt = *cattt;     // Ok: Cat::operator=
    // *catt = *dogg;   // compile error: no conversion from Dog to Cat
    
    delete catt;
    delete cattt;
    delete dogg;

    std::cout << "\n\033[1;34m=== Assign sibling classes ===\033[0m" << std::endl;
    
    Dog dog3;
    Cat cat3;
    // cat1 = dog1; // compile error: Dog can't be assigned to Cat
    cat3.makeSound();

    std::cout << "\n\033[1;34m=== Destructors ===\033[0m" << std::endl;
    
    return 0;
}

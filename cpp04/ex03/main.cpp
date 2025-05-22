/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 01:24:59 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/23 01:54:36 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void subject_test(void) {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
}

void my_test(void) {
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();

    std::cout << "Before assignment:" << std::endl;
    std::cout << "ice->getType(): " << ice->getType() << std::endl;
    std::cout << "cure->getType(): " << cure->getType() << std::endl;

    *cure = *ice; // AMateria::operator=

    std::cout << "After assignment:" << std::endl;
    std::cout << "ice->getType(): " << ice->getType() << std::endl;
    std::cout << "cure->getType(): " << cure->getType() << std::endl;
    
    AMateria* m1 = new Ice();
    AMateria* m2 = m1->clone();
    std::cout << m2->getType() << std::endl;

    Character* alice = new Character("Alice");
    Character* bob = new Character("Bob");

    AMateria* ice1 = new Ice();
    AMateria* cure1 = new Cure();

    alice->equip(ice1);
    alice->equip(cure1);

    alice->use(0, *bob); // Ice
    alice->use(1, *bob); // Cure
    alice->use(3, *bob); //  пусто

    alice->unequip(0);   // ice выпал
    alice->use(0, *bob); //  уже ничего нет

    delete alice;
    delete bob;
    delete ice;  // если ты не сохранил в "пол", нужно удалить вручную


    

    // std::cout << "\n=== Creating Materia Source ===" << std::endl;
    // IMateriaSource* src = new MateriaSource();

    // src->learnMateria(new Ice());
    // src->learnMateria(new Cure());

    // std::cout << "\n=== Creating Character: me ===" << std::endl;
    // ICharacter* me = new Character("me");

    // AMateria* tmp;
    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp = src->createMateria("cure");
    // me->equip(tmp);

    // std::cout << "\n=== Creating Character: bob ===" << std::endl;
    // ICharacter* bob = new Character("bob");

    // std::cout << "\n=== Using Materia ===" << std::endl;
    // me->use(0, *bob); // ice
    // me->use(1, *bob); // cure

    // std::cout << "\n=== Unequipping ice and using again ===" << std::endl;
    // me->unequip(0);
    // me->use(0, *bob); // nothing should happen

    // std::cout << "\n=== Deep Copy Test ===" << std::endl;
    // Character* copy = new Character(*(Character*)me);
    // copy->use(1, *bob); // cure again

    // std::cout << "\n=== Cleanup ===" << std::endl;
    // delete bob;
    // delete me;
    // delete src;
    // delete copy;

}

int main(void) {
    // my_test();
    subject_test();

    return 0;
}

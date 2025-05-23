/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 01:24:59 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/23 02:32:45 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void subject_test() {
    std::cout << "\n\033[1;33m--- Subject test ---\033[0m" << std::endl;
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

void my_test() {
    std::cout << "\n\033[1;36m--- Custom tests ---\033[0m" << std::endl;

    AMateria* ice = new Ice();
    AMateria* cure = new Cure();

    std::cout << "Before assignment:" << std::endl;
    std::cout << "ice->getType(): " << ice->getType() << std::endl;
    std::cout << "cure->getType(): " << cure->getType() << std::endl;

    *cure = *ice; // AMateria::operator=

    std::cout << "After assignment:" << std::endl;
    std::cout << "ice->getType(): " << ice->getType() << std::endl;
    std::cout << "cure->getType(): " << cure->getType() << std::endl;

    AMateria* clone = ice->clone();
    std::cout << "Cloned materia type: " << clone->getType() << std::endl;

    Character* luna = new Character("Luna");
    Character* noctis = new Character("Noctis");

    luna->equip(clone);
    luna->equip(new Cure());

    luna->use(0, *noctis); // ice
    luna->use(1, *noctis); // cure
    luna->use(2, *noctis); // nothing
    luna->unequip(0);
    luna->use(0, *noctis); // again nothing

    std::cout << "\n\033[1;36m--- Deep Copy test ---\033[0m" << std::endl;
    Character* lunaCopy = new Character(*luna);
    lunaCopy->use(1, *noctis); // cure again

    std::cout << "\n\033[1;36m--- Cleanup ---\033[0m" << std::endl;
    delete ice;
    delete cure;
    delete clone;
    delete luna;
    delete noctis;
    delete lunaCopy;
}

void extended_test() {
    std::cout << "\n\033[1;35m--- Extended Logic Test ---\033[0m" << std::endl;

    IMateriaSource* book = new MateriaSource();
    book->learnMateria(new Ice());
    book->learnMateria(new Cure());

    std::cout << "\n[Test createMateria() with unknown type]" << std::endl;
    AMateria* unknown = book->createMateria("fire");
    if (!unknown)
        std::cout << "Correctly returned NULL for unknown materia" << std::endl;

    Character* prompto = new Character("Prompto");

    std::cout << "\n[Test overfilling inventory (more than 4)]" << std::endl;
    prompto->equip(book->createMateria("ice"));
    prompto->equip(book->createMateria("ice"));
    prompto->equip(book->createMateria("cure"));
    prompto->equip(book->createMateria("cure"));
    prompto->equip(book->createMateria("ice")); // должна быть проигнорирована

    std::cout << "\n[Test using empty slot]" << std::endl;
    prompto->use(3, *prompto); // есть
    prompto->use(4, *prompto); // ❌ за пределами
    prompto->use(-1, *prompto); // ❌ отрицательный индекс

    std::cout << "\n[Test unequip and re-equip]" << std::endl;
    prompto->unequip(2); // cure из слота 2
    prompto->use(2, *prompto); // ❌ ничего
    prompto->equip(book->createMateria("cure")); // снова cure в слот 2
    prompto->use(2, *prompto); // ✅ теперь работает

    std::cout << "\n[Cleanup]" << std::endl;
    delete prompto;
    delete book;
}

int main() {
    subject_test();
    my_test();
    extended_test();
    return 0;
}

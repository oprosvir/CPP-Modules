/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 01:24:59 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/21 01:25:25 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main() {
    std::cout << "\n=== Creating Materia Source ===" << std::endl;
    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "\n=== Creating Character: me ===" << std::endl;
    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    std::cout << "\n=== Creating Character: bob ===" << std::endl;
    ICharacter* bob = new Character("bob");

    std::cout << "\n=== Using Materia ===" << std::endl;
    me->use(0, *bob); // ice
    me->use(1, *bob); // cure

    std::cout << "\n=== Unequipping ice and using again ===" << std::endl;
    me->unequip(0);
    me->use(0, *bob); // nothing should happen

    std::cout << "\n=== Deep Copy Test ===" << std::endl;
    Character* copy = new Character(*(Character*)me);
    copy->use(1, *bob); // cure again

    std::cout << "\n=== Cleanup ===" << std::endl;
    delete bob;
    delete me;
    delete src;
    delete copy;

    return 0;
}

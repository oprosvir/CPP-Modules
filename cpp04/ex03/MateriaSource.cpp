/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 01:24:33 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/23 02:23:26 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i)
        _templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    for (int i = 0; i < 4; ++i) {
        if (other._templates[i])
            _templates[i] = other._templates[i]->clone();
        else
            _templates[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            if (_templates[i])
                delete _templates[i];
            if (other._templates[i])
                _templates[i] = other._templates[i]->clone();
            else
                _templates[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i)
        delete _templates[i];
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m)
        return;
    for (int i = 0; i < 4; ++i) {
        if (!_templates[i]) {
            _templates[i] = m->clone();
            std::cout << "Learned materia of type: " << m->getType() << std::endl;
            return;
        }
    }
    std::cout << "MateriaSource full, cannot learn more." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        if (_templates[i] && _templates[i]->getType() == type) {
            std::cout << "Creating materia of type: " << type << std::endl;
            return _templates[i]->clone();
        }
    }
    std::cout << "Materia type '" << type << "' not found" << std::endl;
    return NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 20:07:15 by oprosvir          #+#    #+#             */
/*   Updated: 2025/06/03 21:24:54 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include <iostream>
#include <cstdlib>  // for rand()
#include <ctime>

Base* generate(void) {
    std::srand(std::time(NULL));
    int r = std::rand() % 3;

    switch (r) {
        case 0:
            std::cout << "Generated: A" << std::endl;
            return new A;
        case 1:
            std::cout << "Generated: B" << std::endl;
            return new B;
        case 2:
            std::cout << "Generated: C" << std::endl;
            return new C;
        default:
            return NULL;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "Identified: A (via pointer)" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Identified: B (via pointer)" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Identified: C (via pointer)" << std::endl;
    else
        std::cout << "Identified: Unknown (via pointer)" << std::endl;
}

void identify(Base& p) {
    try {
        dynamic_cast<A&>(p);
        std::cout << "Identified: A (via reference)" << std::endl;
        return;
    } catch (...) {}

    try {
        dynamic_cast<B&>(p);
        std::cout << "Identified: B (via reference)" << std::endl;
        return;
    } catch (...) {}

    try {
        dynamic_cast<C&>(p);
        std::cout << "Identified: C (via reference)" << std::endl;
        return;
    } catch (...) {}

    std::cout << "Identified: Unknown (via reference)" << std::endl;
}
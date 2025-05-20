/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 00:22:50 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/20 20:16:14 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
    std::cout << "\n\033[1;32m=== Default Constructor Test ===\033[0m" << std::endl;
    ClapTrap bot1;
    std::cout << bot1 << std::endl;

    std::cout << "\n\033[1;32m=== Named Constructor Test ===\033[0m" << std::endl;
    ClapTrap bot2("Pinky");
    std::cout << bot2 << std::endl;

    std::cout << "\n\033[1;32m=== Copy Constructor Test ===\033[0m" << std::endl;
    ClapTrap bot3(bot2);

    std::cout << "\n\033[1;32m=== Assignment Operator Test ===\033[0m" << std::endl;
    ClapTrap a("Original");
    ClapTrap b("Target");

    b = a;
    std::cout << b << std::endl;

    std::cout << "\n\033[1;32m=== Attack Test ===\033[0m" << std::endl;
    bot1.attack("a zombie");

    std::cout << "\n\033[1;32m=== Take Damage Test ===\033[0m" << std::endl;
    bot1.takeDamage(-300);
    bot1.takeDamage(2218653229);
    bot1.takeDamage(30);
    bot2.takeDamage(4);

    std::cout << "\n\033[1;32m=== Repair Test ===\033[0m" << std::endl;
    bot1.beRepaired(10);
    bot2.beRepaired(2147483649);
    bot2.beRepaired(-300);
    bot2.beRepaired(50);
    b.beRepaired(5);

    std::cout << "\n\033[1;32m=== Exhaust Energy ===\033[0m" << std::endl;
    for (int i = 0; i < 11; ++i) {
        std::cout << "[Turn " << i + 1 << "] ";
        bot3.attack("you");
        std::cout << "Remaining energy: " << bot3.getEnergyPoints() << std::endl;
    }
    
    std::cout << "\n\033[1;32m=== Dead bot tries to act ===\033[0m" << std::endl;
    ClapTrap bot4("DeadBot");
    bot4.takeDamage(100);
    bot4.attack("Training Dummy");
    bot4.beRepaired(10);

    std::cout << "\n\033[1;32m=== Destructors Called ===\033[0m" << std::endl;
    return 0;
}
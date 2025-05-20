/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:43:07 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/20 21:32:26 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void) {
    std::cout << "\n\033[1;34m=== [ ScavTrap Constructors ] ===\033[0m" << std::endl;
    ScavTrap* scav1 = new ScavTrap;
    ScavTrap scav2("Guardian");
    ClapTrap clap1("Boris");
    
    std::cout << scav2 << std::endl;
    std::cout << clap1 << std::endl;
    delete(scav1);
    
    std::cout << "\n\033[1;34m=== [ ScavTrap Copy & Assignment ] ===\033[0m" << std::endl;
    ScavTrap scav3(scav2);
    ScavTrap scav4;
    scav4 = scav2;

    std::cout << "\n\033[1;34m=== [ ScavTrap Attack ] ===\033[0m" << std::endl;
    scav2.attack("intruder");
    clap1.attack("intruder");

    std::cout << "\n\033[1;34m=== [ ScavTrap Inherited Functions ] ===\033[0m" << std::endl;
    scav2.takeDamage(20);
    scav2.beRepaired(10);
    scav2.beRepaired(50);
    scav2.beRepaired(1);
    scav2.takeDamage(150);
    scav2.beRepaired(10);

    clap1.takeDamage(3);
    clap1.beRepaired(2);

    std::cout << "\n\033[1;34m=== [ ScavTrap Guard Mode ] ===\033[0m" << std::endl;
    scav2.guardGate();

    std::cout << "\n\033[1;34m=== [ ScavTrap Destructor Test ] ===\033[0m" << std::endl;
    
    return 0;
}
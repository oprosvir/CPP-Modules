/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:41:07 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/20 22:03:24 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void) {
    std::cout << "\n\033[1;34m=== [ FragTrap Constructors ] ===\033[0m" << std::endl;
    FragTrap* frag1 = new FragTrap; // default
    FragTrap frag2("Froggy");       // named
    ClapTrap clap("Clappy");        // base class object
    delete frag1;

    std::cout << "\n\033[1;34m=== [ Output Operator Test ] ===\033[0m" << std::endl;
    std::cout << frag2 << std::endl;
    std::cout << clap << std::endl;

    std::cout << "\n\033[1;34m=== [ FragTrap Copy & Assignment ] ===\033[0m" << std::endl;
    FragTrap frag3(frag2);
    FragTrap frag4;
    frag4 = frag2;

    std::cout << "\n\033[1;34m=== [ FragTrap Inherited Functions ] ===\033[0m" << std::endl;
    frag2.attack("target dummy");
    frag2.takeDamage(30);
    frag2.beRepaired(20);
    frag2.beRepaired(100); // check cap
    frag2.takeDamage(150);
    frag2.beRepaired(10);  // dead — shouldn't repair

    std::cout << "\n\033[1;34m=== [ FragTrap Special Ability ] ===\033[0m" << std::endl;
    frag3.highFivesGuys();

    std::cout << "\n\033[1;34m=== [ Destruction Test ] ===\033[0m" << std::endl;

    return 0;
}
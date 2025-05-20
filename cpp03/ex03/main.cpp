/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 23:06:47 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/21 00:17:46 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void) {
    std::cout << "\n\033[1;34m=== [ DiamondTrap Constructors ] ===\033[0m" << std::endl;
    DiamondTrap d1("Diamondy");
    DiamondTrap d2(d1); // copy
    DiamondTrap d3;
    d3 = d1; // assignment

    std::cout << "\n\033[1;34m=== [ DiamondTrap Status Output ] ===\033[0m" << std::endl;
    std::cout << d1 << std::endl;

    std::cout << "\n\033[1;34m=== [ Inherited Actions ] ===\033[0m" << std::endl;
    d1.attack("Training Dummy");
    d1.takeDamage(42);
    d1.beRepaired(20);

    std::cout << "\n\033[1;34m=== [ DiamondTrap Identity ] ===\033[0m" << std::endl;
    d1.whoAmI();

    std::cout << "\n\033[1;34m=== [ Destructor Order Test ] ===\033[0m" << std::endl;

    return 0;
}
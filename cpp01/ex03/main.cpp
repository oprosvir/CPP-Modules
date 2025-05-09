/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:18:31 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/09 19:42:12 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void) {
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        // Weapon club2("laser gun");
        HumanB jim("Jim");
        // jim.attack();
        jim.setWeapon(club);
        jim.attack();
        // jim.setWeapon(club2);
        // jim.attack();
        club.setType("some other type of club");
        // club2.setType("stone");
        jim.attack();
        // jim.setWeapon(Weapon("gun"));
    }
    return 0;
}

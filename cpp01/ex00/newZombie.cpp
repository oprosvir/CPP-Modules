/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:34:26 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/09 00:10:09 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// heap allocation
Zombie* newZombie(std::string name) {
    Zombie* zombie = new Zombie(name);
    zombie->announce();
    return zombie;
}
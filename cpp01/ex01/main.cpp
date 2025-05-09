/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:33:41 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/09 13:05:05 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
    int N = 5;
    Zombie* horde = zombieHorde(N, "Gavrik");
    if (!horde)
        return 1;

    for (int i = 0; i < N; ++i)
        horde[i].announce();
    delete[] horde;

    return 0;
}
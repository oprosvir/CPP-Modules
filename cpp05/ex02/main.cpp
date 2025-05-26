/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:04:56 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/26 19:46:11 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
    std::cout << "=== ShrubberyCreationForm test OK ===\n";

    Bureaucrat bob("Bob", 100); // grade < 137 -> ок
    ShrubberyCreationForm shrub("garden");

    std::cout << shrub << std::endl;

    bob.signForm(shrub);
    std::cout << shrub << std::endl;

    bob.executeForm(shrub);

    std::cout << "\n=== Cannot execute (grade too low) ===\n";

    Bureaucrat junior("Junior", 138);
    ShrubberyCreationForm shrub1("backyard");

    junior.signForm(shrub1);
    junior.executeForm(shrub1);
    junior.incrementGrade();
    junior.executeForm(shrub1);

    return 0;
}
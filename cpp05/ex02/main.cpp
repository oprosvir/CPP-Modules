/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:04:56 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/26 22:29:15 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <ctime>

int main(void) {
    std::srand(std::time(0));
    std::cout << "=== ShrubberyCreationForm test OK ===\n";

    Bureaucrat bob("Bob", 100); // sign (145), exec (137)
    ShrubberyCreationForm shrub("garden");
    std::cout << shrub << std::endl;
    bob.signForm(shrub);
    std::cout << shrub << std::endl;
    bob.executeForm(shrub);

    std::cout << "\n=== Cannot execute (grade too low) ===\n";

    Bureaucrat junior("Junior", 138);
    ShrubberyCreationForm shrub1("backyard");
    std::cout << shrub1 << std::endl;
    std::cout << junior << std::endl;
    junior.signForm(shrub1);
    junior.executeForm(shrub1);
    // junior.incrementGrade();
    // junior.executeForm(shrub1);

    std::cout << "\n=== RobotomyRequestForm — sign and execute ===\n";
    
    Bureaucrat alice("Alice", 40); // sign (72), exec (45)
    RobotomyRequestForm robo("Bender");
    std::cout << robo << std::endl;
    alice.signForm(robo);
    alice.executeForm(robo);
    alice.executeForm(robo);
    alice.executeForm(robo);

    std::cout << "\n=== RobotomyRequestForm — execute without signing ===\n";
    Bureaucrat bibo("Bibo", 20);
    RobotomyRequestForm robo2("Marvin");
    bob.executeForm(robo2);

    return 0;
}
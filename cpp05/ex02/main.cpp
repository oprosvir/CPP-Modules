/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:04:56 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/27 01:00:07 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>

int main(void) {
    std::srand(std::time(0));
    std::cout << "=== ShrubberyCreationForm — sign and execute ===\n";

    Bureaucrat bob("Bob", 100); // sign (145), exec (137)
    ShrubberyCreationForm shrub("garden");
    std::cout << shrub << std::endl;
    std::cout << bob << std::endl;
    bob.signForm(shrub);
    std::cout << shrub << std::endl;
    bob.executeForm(shrub);

    std::cout << "\n=== ShrubberyCreationForm - grade too low ===\n";

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
    std::cout << alice << std::endl;
    alice.signForm(robo);
    alice.executeForm(robo);
    alice.executeForm(robo);
    alice.executeForm(robo);

    std::cout << "\n=== RobotomyRequestForm — execute without signing ===\n";
    Bureaucrat bibo("Bibo", 20);
    RobotomyRequestForm robo2("Marvin");
    std::cout << bibo << std::endl;
    std::cout << robo2 << std::endl;
    bibo.executeForm(robo2);

    std::cout << "\n=== PresidentialPardonForm — sign and execute ===\n";

    Bureaucrat president("President", 1);   // sign (25), exec (5)
    PresidentialPardonForm pardon("Arthur Dent");
    std::cout << president << std::endl;
    std::cout << pardon << std::endl;
    president.signForm(pardon);
    std::cout << pardon << std::endl;
    president.executeForm(pardon);

    std::cout << "\n=== PresidentialPardonForm — insufficient grade to execute ===\n";
    
    Bureaucrat intern("Intern", 25);
    PresidentialPardonForm restricted("Trillian");
    std::cout << intern << std::endl;
    std::cout << restricted << std::endl;
    intern.signForm(restricted);
    intern.executeForm(restricted);
    
    return 0;
}
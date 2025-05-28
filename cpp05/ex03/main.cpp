/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:41:14 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/27 23:19:00 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>

int main(void) {
    std::srand(std::time(0));
    std::cout << "\n=== Intern — valid form creation ===\n";

    Intern someIntern;
    AForm* form = someIntern.makeForm("robotomy request", "Bender");
    if (form) {
        std::cout << *form << std::endl;
        Bureaucrat admin("Admin", 1);
        std::cout << admin << std::endl;
        admin.signForm(*form);
        admin.executeForm(*form);
        delete form;
    }

    std::cout << "\n=== Intern — unknown form ===\n";

    AForm* invalidForm = someIntern.makeForm("pardon me please", "Nobody");
    if (!invalidForm) {
        std::cout << "Form creation failed as expected.\n";
    } else {
        std::cout << "Unexpectedly created form: " << *invalidForm << std::endl;
        delete invalidForm;
    }

    return 0;
}
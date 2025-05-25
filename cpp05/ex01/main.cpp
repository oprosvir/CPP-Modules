/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:16:40 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/26 00:00:15 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
    std::cout << "=== VALID FORM CREATION ===\n";
    try {
        Form f1("TaxForm", 50, 25);
        std::cout << f1 << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== INVALID FORM CREATION (grade too low) ===\n";
    try {
        Form f2("InvalidForm", 160, 10);
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== INVALID FORM CREATION (grade too high) ===\n";
    try {
        Form f3("InvalidForm2", 1, 0);
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== BE SIGNED — SUCCESS ===\n";
    try {
        Bureaucrat senior("Senior", 20);
        Form form("Contract", 50, 30);
        form.beSigned(senior);
        std::cout << "Form signed: " << form << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== BE SIGNED — FAIL (grade too low) ===\n";
    try {
        Bureaucrat junior("Junior", 100);
        Form form("SecretForm", 40, 20);
        form.beSigned(junior);
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Bureaucrat::signForm — success ===\n";
    {
        Bureaucrat boss("Boss", 10);
        Form permit("BuildingPermit", 50, 20);
        boss.signForm(permit);
        std::cout << permit << std::endl;
    }

    std::cout << "\n=== Bureaucrat::signForm — fail ===\n";
    {
        Bureaucrat intern("Intern", 120);
        Form paper("HRApproval", 50, 20);
        intern.signForm(paper);
        std::cout << paper << std::endl;
    }

    return 0;
}

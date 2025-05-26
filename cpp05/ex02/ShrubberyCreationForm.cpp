/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:06:27 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/26 19:28:58 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137, "unknown") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm&) {
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    this->checkExecutability(executor);
    std::string filename = this->getTarget() + "_shrubbery";
    std::ofstream out(filename.c_str());
    if (!out.is_open()) {
        std::cerr << "Error: Could not open file for writing." << std::endl;
        return;
    }

    out << "       _-_       \n"
           "    /~~   ~~\\    \n"
           " /~~         ~~\\ \n"
           "{               }\n"
           " \\  _-     -_  / \n"
           "   ~  \\\\ //  ~   \n"
           "_- -   | | _- _  \n"
           "  _ -  | |   -_  \n"
           "      // \\\\      \n";
    out.close();
}
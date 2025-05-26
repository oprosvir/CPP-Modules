/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:07:01 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/26 22:22:15 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45, "unknown") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm&) {
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    this->checkExecutability(executor);

    std::cout << "* drilling noises * BZZZZZZZZZZZ...\n";

    if (std::rand() % 2 == 0) {
        std::cout << "\033[32m"
                  << this->getTarget() << " has been robotomized successfully\n"
                  << "\033[0m";
    } else {
        std::cout << "\033[31m"
                  << "Robotomy failed on " << this->getTarget() << "\n"
                  << "\033[0m";
    }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:15:57 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/26 19:05:49 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Default constructor
AForm::AForm()
    : _name("Untitled"), _isSigned(false), _gradeToSign(150),
    _gradeToExecute(150), _target("None") {}

// Param constructor
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute, const std::string& target)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign),
    _gradeToExecute(gradeToExecute), _target(target)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

// Copy constructor
AForm::AForm(const AForm& other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute),
      _target(other._target) {}
      
// Assignment operator
AForm& AForm::operator=(const AForm&) {
    return *this;
}

// Destructor
AForm::~AForm() {}

const std::string& AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }
const std::string& AForm::getTarget() const { return _target; }

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

void AForm::checkExecutability(const Bureaucrat& executor) const {
    if (!this->isSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException();
}

// Exceptions
const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm: Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm: Grade too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "AForm: Form is not signed";
}

std::ostream& operator<<(std::ostream& out, const AForm& form) {
    out << "Form \"" << form.getName()
        << "\", signed: " << (form.isSigned() ? "yes" : "no")
        << ", grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute()
        << ", target: " << form.getTarget();
    return out;
}
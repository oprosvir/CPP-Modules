/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:15:57 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/26 17:24:19 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Default constructor
AForm::AForm() : _name("Untitled"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

// Param constructor
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) 
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

// Copy constructor
AForm::AForm(const AForm& other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}
      
// Assignment operator
AForm& AForm::operator=(const AForm& other) {
    if (this != &other)
        this->_isSigned = other._isSigned;
    return *this;
}

// Destructor
AForm::~AForm() {}

const std::string& AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

// Exceptions
const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm: Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm: Grade too low";
}

std::ostream& operator<<(std::ostream& out, const AForm& form) {
    out << "AForm \"" << form.getName()
        << "\", signed: " << (form.isSigned() ? "yes" : "no")
        << ", grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute();
    return out;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:12:14 by natferna          #+#    #+#             */
/*   Updated: 2025/11/09 23:12:14 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Unknown"), _isSigned(false), _signGrade(150), _execGrade(150) {}

AForm::AForm(const std::string &name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : _name(other._name), _isSigned(other._isSigned),
      _signGrade(other._signGrade), _execGrade(other._execGrade) {}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _isSigned; }
int AForm::getSignGrade() const { return _signGrade; }
int AForm::getExecGrade() const { return _execGrade; }

void AForm::beSigned(Bureaucrat const &b) {
    if (b.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

void AForm::checkExecution(Bureaucrat const &executor) const {
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _execGrade)
        throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw() { return "Form: grade too high!"; }
const char* AForm::GradeTooLowException::what() const throw() { return "Form: grade too low!"; }
const char* AForm::FormNotSignedException::what() const throw() { return "Form: not signed!"; }

std::ostream &operator<<(std::ostream &out, const AForm &f) {
    out << f.getName() << " | signed: " << (f.isSigned() ? "yes" : "no")
        << " | grade to sign: " << f.getSignGrade()
        << " | grade to execute: " << f.getExecGrade();
    return out;
}

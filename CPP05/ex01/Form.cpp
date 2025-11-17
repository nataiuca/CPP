/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 22:50:52 by natferna          #+#    #+#             */
/*   Updated: 2025/11/09 22:50:52 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string &_name, int _gradeToSign, int _gradeToExecute)
    : _name(_name), _isSigned(false), _gradeToSign(_gradeToSign), _gradeToExecute(_gradeToExecute)
{
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form& Form::operator=(const Form &other) {
    if (this != &other)
        this->_isSigned = other._isSigned;
    return *this;
}

Form::~Form() {}

const std::string &Form::getName() const { return _name; }
bool Form::getIsSigned() const { return _isSigned; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }

void Form::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form: grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form: grade too low!";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "Form " << form.getName()
        << " | Signed: " << (form.getIsSigned() ? "Yes" : "No")
        << " | Grade to sign: " << form.getGradeToSign()
        << " | Grade to execute: " << form.getGradeToExecute();
    return out;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 21:23:56 by natferna          #+#    #+#             */
/*   Updated: 2025/11/09 23:01:38 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string _name, int _grade) : _name(_name), _grade(_grade) {
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(Form &form)
{
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception &e) {
        std::cout << _name << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}


const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "bureaucrat: grade too high!";
} 

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "bureaucrat: grade too low!"; 
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return out;
}
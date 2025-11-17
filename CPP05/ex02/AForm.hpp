/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:11:40 by natferna          #+#    #+#             */
/*   Updated: 2025/11/09 23:11:40 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
    const std::string _name;
    bool _isSigned;
    const int _signGrade;
    const int _execGrade;

public:
    AForm();
    AForm(const std::string &name, int signGrade, int execGrade);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();

    const std::string &getName() const;
    bool isSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    void beSigned(Bureaucrat const &b);

    void checkExecution(Bureaucrat const &executor) const;

    virtual void execute(Bureaucrat const &executor) const = 0;

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif

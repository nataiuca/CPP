/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 22:49:49 by natferna          #+#    #+#             */
/*   Updated: 2025/11/09 22:49:49 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <stdexcept>

class Bureaucrat;

class Form {
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
    // Constructors & Destructor
    Form(const std::string &name, int gradeToSign, int gradeToExecute);
    Form(const Form &other);
    Form& operator=(const Form &other);
    ~Form();

    // Getters
    const std::string &getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Methods
    void beSigned(class Bureaucrat &bureaucrat);

    // Exceptions
    class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw();
    };
};

// << operator
std::ostream& operator<<(std::ostream &out, const Form &form);

#endif

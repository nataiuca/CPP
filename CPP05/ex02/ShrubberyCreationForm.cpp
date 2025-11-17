/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:30:06 by natferna          #+#    #+#             */
/*   Updated: 2025/11/09 23:30:06 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other)
       AForm::operator= (other); // solo copiamos lo no-const del hijo
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    checkExecution(executor); // función protegida en AForm

    std::ofstream ofs((_target + "_shrubbery").c_str());
    if (!ofs.is_open())
        throw std::runtime_error("Failed to open output file");

    ofs << "       _-_\n"
           "    /~~   ~~\\\n"
           " /~~         ~~\\\n"
           "{               }\n"
           " \\  _-     -_  /\n"
           "   ~  \\\\ //  ~\n"
           "_- -   | | _- _\n"
           "  _ -  | |   -_\n"
           "      // \\\\\n";
    ofs.close();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:34:30 by natferna          #+#    #+#             */
/*   Updated: 2025/11/09 23:34:30 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::srand(std::time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeAction() const {
    std::cout << "Bzzzz... drilling noises... ";
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "The robotomy failed on " << _target << "!" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    checkExecution(executor);
    executeAction();
}

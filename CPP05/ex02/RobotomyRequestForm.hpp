/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:33:59 by natferna          #+#    #+#             */
/*   Updated: 2025/11/09 23:33:59 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// RobotomyRequestForm.hpp
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
private:
    const std::string _target;

    void executeAction() const;

public:
    RobotomyRequestForm(const std::string &target);
    virtual ~RobotomyRequestForm();
    void execute(Bureaucrat const &executor) const;
};

#endif
 
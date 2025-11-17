/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:36:02 by natferna          #+#    #+#             */
/*   Updated: 2025/11/09 23:36:02 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm {
private:
    const std::string _target;

    void executeAction() const;

public:
    PresidentialPardonForm(const std::string &target);
    virtual ~PresidentialPardonForm();
    void execute(Bureaucrat const &executor) const;
};

#endif

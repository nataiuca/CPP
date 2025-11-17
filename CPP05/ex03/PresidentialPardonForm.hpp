#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
private:
    std::string _target;

public:
    PresidentialPardonForm(const std::string &target);
    virtual ~PresidentialPardonForm();

    void execute(Bureaucrat const &executor) const;
};

#endif

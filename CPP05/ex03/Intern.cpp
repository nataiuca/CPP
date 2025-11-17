#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// Constructor / destructor / copia
Intern::Intern() {}
Intern::Intern(const Intern &other) { (void)other; }
Intern &Intern::operator=(const Intern &other) { (void)other; return *this; }
Intern::~Intern() {}

const char* Intern::FormNotFoundException::what() const throw() {
    return "Intern: requested form does not exist";
}

// Métodos miembro "factory"
AForm* Intern::_makeShrubbery(const std::string &target) const {
    return new ShrubberyCreationForm(target);
}
AForm* Intern::_makeRobotomy(const std::string &target) const {
    return new RobotomyRequestForm(target);
}
AForm* Intern::_makePresidential(const std::string &target) const {
    return new PresidentialPardonForm(target);
}

// makeForm usando array de punteros a miembro
AForm* Intern::makeForm(const std::string &formName, const std::string &target) const {
    // array con nombres exactamente como pide el subject
    const std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    // puntero a método miembro: AForm* (Intern::*)(const std::string&) const
    typedef AForm* (Intern::*Maker)(const std::string &) const;

    Maker creators[3] = {
        &Intern::_makeShrubbery,
        &Intern::_makeRobotomy,
        &Intern::_makePresidential
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == names[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*creators[i])(target);
        }
    }


    std::cout << "Intern: form '" << formName << "' does not exist" << std::endl;
    return NULL;
}

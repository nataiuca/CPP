#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern {
public:
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();

    // makeForm: crea un AForm dinámicamente según formName
    AForm* makeForm(const std::string &formName, const std::string &target) const;

    // Excepción en caso de formulario desconocido
    class FormNotFoundException : public std::exception {
    public:
        const char* what() const throw();
    };

private:
    // Métodos miembro "factory" (devuelven un nuevo AForm*)
    AForm* _makeShrubbery(const std::string &target) const;
    AForm* _makeRobotomy(const std::string &target) const;
    AForm* _makePresidential(const std::string &target) const;
};

#endif

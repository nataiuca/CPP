#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    Intern someRandomIntern;
    AForm *form;

    Bureaucrat boss("Boss", 1);
    Bureaucrat mid("Mid", 70);

    // ✅ Shrubbery
    form = someRandomIntern.makeForm("shrubbery creation", "home");
    if (form) {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    // ✅ Robotomy
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form) {
        mid.signForm(*form);
        mid.executeForm(*form);
        delete form;
    }

    // ✅ Pardon
    form = someRandomIntern.makeForm("presidential pardon", "Arthur");
    if (form) {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    // ❌ Invalido
    form = someRandomIntern.makeForm("make me a sandwich", "nobody");
    if (!form)
        std::cout << "Correct: form not created.\n";

    return 0;
}

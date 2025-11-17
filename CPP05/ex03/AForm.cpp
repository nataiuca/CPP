#include "AForm.hpp"

AForm::AForm() : _name("Unknown"), _signed(false), _signGrade(150), _execGrade(150) {}

AForm::AForm(const std::string &name, int sGrade, int eGrade)
: _name(name), _signed(false), _signGrade(sGrade), _execGrade(eGrade) {
    if (sGrade < 1 || eGrade < 1)
        throw GradeTooHighException();
    if (sGrade > 150 || eGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
: _name(other._name), _signed(other._signed),
  _signGrade(other._signGrade), _execGrade(other._execGrade) {}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other)
        _signed = other._signed;
    return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _signed; }
int AForm::getSignGrade() const { return _signGrade; }
int AForm::getExecGrade() const { return _execGrade; }

void AForm::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > _signGrade)
        throw GradeTooLowException();
    _signed = true;
}

void AForm::checkExecution(const Bureaucrat &executor) const {
    if (!_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > _execGrade)
        throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "form: grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "form: grade too low!";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "form: not signed!";
}

std::ostream &operator<<(std::ostream &out, const AForm &f) {
    out << f.getName() << " | signed: " << (f.isSigned() ? "yes" : "no")
        << " | grade to sign: " << f.getSignGrade()
        << " | grade to exec: " << f.getExecGrade();
    return out;
}

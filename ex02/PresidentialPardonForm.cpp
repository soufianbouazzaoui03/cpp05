#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& cpy) : AForm(cpy) {
    target = cpy.target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& cpy) {
    if (this != & cpy) {
        target = cpy.target;
    }
    return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if (!getSign())
        throw FormIsNotSigned();
    if (executor.getGrade() > getGradeToExc())
        throw GradeTooHighException();
    else {
        std::cout<<target<<" > has been pardoned by Zaphod Beeblebrox\n";
    }
}

PresidentialPardonForm::~PresidentialPardonForm() {}
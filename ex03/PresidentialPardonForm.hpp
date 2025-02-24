#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
    std::string target;
    PresidentialPardonForm();

public:
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(PresidentialPardonForm& cpy);
    PresidentialPardonForm& operator=(PresidentialPardonForm& cpy);
    ~PresidentialPardonForm();

    void execute(const Bureaucrat& executor) const;
};

#endif
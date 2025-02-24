#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {

}
Intern::Intern(Intern& cpy){
    (void)cpy;
}
Intern& Intern::operator=(Intern& cpy){
    (void)cpy;
    return *this;
}

Intern::~Intern(){}

AForm* Intern::create_shrubbery(std::string& target) {
    return new ShrubberyCreationForm(target);
}
AForm* Intern::create_robot(std::string& target) {
    return new RobotomyRequestForm(target);
}
AForm* Intern::create_presidential(std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target) {
    typedef AForm* (Intern::*MemberFun)(std::string& target); 

    MemberFun funs[3] = {
        &Intern::create_robot,
        &Intern::create_shrubbery,
        &Intern::create_presidential
    };

    std::string targets[3] = {
        "robotomy request",
        "shrubbery Creation",
        "presidential pardon"
    };

    for (int i = 0; i < 3; i++) {
        if (targets[i] == name) {
            return (this->*funs[i])(target);
        }
    }
    throw FormNotFoundException();
}
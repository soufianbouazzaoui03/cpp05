#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& cpy) : AForm(cpy) {
    target = cpy.target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& cpy)  {
    if (this != & cpy) {
        target = cpy.target;
    }
    return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (!getSign())
        throw FormIsNotSigned();
    if (executor.getGrade() > getGradeToExc())
        throw GradeTooHighException();
    else {
        std::cout<<"Drilling !!!!\n";
        if (rand() % 2)
            std::cout<<target<<" has been robotomized\n";
        else
            std::cout<<"has been robotomized\n";
    }
}

RobotomyRequestForm::~RobotomyRequestForm() {}
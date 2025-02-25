#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
private:
    std::string target;
    RobotomyRequestForm();

public:
    RobotomyRequestForm(const std::string& target);
    ~RobotomyRequestForm();
    RobotomyRequestForm(RobotomyRequestForm& cpy);
    RobotomyRequestForm& operator=(RobotomyRequestForm& cpy);

    void execute(const Bureaucrat& executor) const;
};

#endif
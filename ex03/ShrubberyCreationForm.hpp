
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class ShrubberyCreationForm : public AForm {
    private:
        ShrubberyCreationForm();
        std::string target;
    public:
        ShrubberyCreationForm(std::string _target);
        ShrubberyCreationForm(ShrubberyCreationForm& cpy);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm& operator=(ShrubberyCreationForm& cpy);
        void execute(const Bureaucrat& executor) const;
};

#endif



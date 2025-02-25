#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern {
    public :
        Intern();
        Intern(Intern& cpy);
        Intern& operator=(Intern& cpy); 
        AForm* create_shrubbery(std::string& target);
        AForm* create_robot(std::string& target);
        AForm* create_presidential(std::string& target);
        ~Intern();

        AForm* makeForm(std::string name, std::string target);

        class FormNotFoundException : public std::exception {
            const char* what() const throw();
        };

};

#endif
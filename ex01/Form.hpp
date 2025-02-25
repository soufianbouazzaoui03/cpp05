#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        const std::string   name;
        bool                sign;
        const int           grade_to_sign;
        const int           grade_to_exc;
    public:
        Form();
        Form(std::string _name, int _grade_to_sign, int _grade_to_exc);
        Form(Form& cpy);
        Form& operator=(Form& cpy);
        ~Form();
        std::string getName() const;
        bool getSign() const;
        int getGradeToSign() const;
        int getGradeToExc() const;
        void beSigned(Bureaucrat& bureaucrat);

        class GradeTooHighException : public std::exception {
            public :
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public :
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& obj, const Form& f);

#endif
#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

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
        std::string getName();
        bool getSign();
        int getGradeToSign();
        int getGradeToExc();
        void beSigned(Bureaucrat& bureaucrat);

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw() {
                    return "Grade too high";
                }
        };

        class GradeTooLowException : public std::exception {
            public :
                const char* what() const throw() {
                    return "Grade too low";
                }
        };
};

std::ostream& operator<<(std::ostream obj, const Form& f);

#endif
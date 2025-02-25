#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <fstream>

class Bureaucrat;

class AForm {
    private:
        const std::string   name;
        bool                sign;
        const int           grade_to_sign;
        const int           grade_to_exc;
    public:
        AForm();
        AForm(std::string _name, int _grade_to_sign, int _grade_to_exc);
        AForm(AForm& cpy);
        AForm& operator=(AForm& cpy);
        virtual ~AForm();
        std::string getName() const;
        bool getSign() const;
        int getGradeToSign() const;
        int getGradeToExc() const;
        void beSigned(Bureaucrat& bureaucrat);
        virtual void execute(const Bureaucrat& executor) const = 0;
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

        class FormIsNotSigned : public std::exception {
            public :
                const char* what() const throw() {
                    return "Form Is Not Signed";
                }
        };
};

std::ostream& operator<<(std::ostream obj, const AForm& f);

#endif
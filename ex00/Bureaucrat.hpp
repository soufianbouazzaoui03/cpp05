#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string _name, int _grade);
        Bureaucrat(Bureaucrat& cpy);
        Bureaucrat& operator=(const Bureaucrat& cpy);
        ~Bureaucrat();
        std::string getName() const;
        int getGrade() const;
        void    increment();
        void    decrement();

        class GradeTooHighException : public std::exception {
            public :
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public :
                const char* what() const throw();
        };

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);


#endif
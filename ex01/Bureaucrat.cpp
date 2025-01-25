#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name) {
    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    
    grade = _grade;
}

Bureaucrat::Bureaucrat(Bureaucrat& cpy) : name(cpy.name), grade(cpy.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& cpy) {
    if (this != &cpy)
    {
        grade = cpy.grade;
    }
    return *this;
}

std::string Bureaucrat::getName() const{
    return (name);
}

int Bureaucrat::getGrade() const {
    return (grade);
}

void    Bureaucrat::increment() {
    if (grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    --grade;
}

void    Bureaucrat::decrement() {
    if (grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    ++grade;
}

Bureaucrat::~Bureaucrat() {
    std::cout<< "Bureaucrat destructor\n";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
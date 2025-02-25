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

void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << name << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

Bureaucrat::~Bureaucrat() {
    std::cout<< "Bureaucrat destructor\n";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}


const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
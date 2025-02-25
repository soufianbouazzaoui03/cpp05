#include "Form.hpp"

Form::Form() : name("Defaut"), sign(false), grade_to_sign(150) , grade_to_exc(150){}

Form::Form(std::string _name, int _grade_to_sign, int _grade_to_exc) : 
    name(_name), sign(false), grade_to_sign(_grade_to_sign), grade_to_exc(_grade_to_exc) {

        if (grade_to_exc < 1 || grade_to_sign < 1)
            throw Form::GradeTooHighException();
        if (grade_to_exc > 150 || grade_to_sign > 150)
            throw Form::GradeTooLowException();
    }

Form::Form(Form& cpy) :
    name(cpy.name),
    sign(cpy.sign),
    grade_to_sign(cpy.grade_to_sign),
    grade_to_exc(cpy.grade_to_exc) {

    }

Form& Form::operator=(Form& cpy) {
    if (this != &cpy)
    {
        sign = cpy.sign;
    }
    return *this;
}

std::string Form::getName() const {
    return name;
}

bool Form::getSign() const {
    return sign;
}

int Form::getGradeToSign() const {
    return grade_to_sign;
}

int Form::getGradeToExc() const {
    return grade_to_exc;
}

void Form::beSigned(Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > grade_to_sign )
        throw Form::GradeTooLowException();
    sign = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade too high";
}


const char* Form::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

Form::~Form(){}


std::ostream& operator<<(std::ostream& obj, const Form& f) {
    obj << "Form: " << f.getName() 
        << ", Signed: " << (f.getSign() ? "Yes" : "No")
        << ", Grade to sign: " << f.getGradeToSign()
        << ", Grade to execute: " << f.getGradeToExc();
    return obj;
}
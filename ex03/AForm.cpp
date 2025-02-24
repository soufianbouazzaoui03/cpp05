#include "AForm.hpp"

AForm::AForm() : name("Defaut"), sign(false), grade_to_sign(150), grade_to_exc(150){}

AForm::AForm(std::string _name, int _grade_to_sign, int _grade_to_exc) : 
    name(_name), sign(false), grade_to_sign(_grade_to_sign), grade_to_exc(_grade_to_exc) {

        if (grade_to_exc < 1 || grade_to_sign < 1)
            throw AForm::GradeTooHighException();
        if (grade_to_exc > 150 || grade_to_sign > 150)
            throw AForm::GradeTooLowException();
    }

AForm::AForm(AForm& cpy) :
    name(cpy.name),
    sign(cpy.sign),
    grade_to_sign(cpy.grade_to_sign),
    grade_to_exc(cpy.grade_to_exc) {

    }

AForm& AForm::operator=(AForm& cpy) {
    if (this != &cpy)
    {
        sign = cpy.sign;
    }
    return *this;
}

std::string AForm::getName() const{
    return name;
}

bool AForm::getSign() const{
    return sign;
}

int AForm::getGradeToSign() const{
    return grade_to_sign;
}

int AForm::getGradeToExc() const{
    return grade_to_exc;
}

void AForm::beSigned(Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > grade_to_sign )
        throw AForm::GradeTooLowException();
    sign = true;
}

AForm::~AForm(){}

std::ostream& operator<<(std::ostream& obj, const AForm& f) {
    obj << "Form: " << f.getName() 
        << ", Signed: " << (f.getSign() ? "Yes" : "No")
        << ", Grade to sign: " << f.getGradeToSign()
        << ", Grade to execute: " << f.getGradeToExc();
    return obj;
}
#include "Form.hpp"


// #include "Bureaucrat.hpp"

// class Form {
//     private:
//         const std::string   name;
//         bool                sign;
//         const int           grade_to_sign;
//         const int           grade_to_exc;
//     public:
//         Form();
//         Form(std::string _name, int _grade_to_sign, int _grade_to_exc);
//         Form(Form& cpy);
//         Form& operator=(Form& cpy);
//         ~Form();
//         std::string getName();
//         bool getSign();
//         int getGradeToSign();
//         int getGradeToExc();
//         void beSigned(Bureaucrat& bureaucrat);

//         class GradeTooHighException : public std::exception {
//             public:
//                 const char* what() const throw() {
//                     return "Grade too high";
//                 }
//         };

//         class GradeTooLowException : public std::exception {
//             public :
//                 const char* what() const throw() {
//                     return "Grade too low";
//                 }
//         };
// };

// std::ostream& operator<<(std::ostream obj, const Form& f);

// #endif

Form::Form() : name("Defaut"), sign(false), grade_to_exc(150), grade_to_sign(150){}

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

std::string Form::getName() {
    return name;
}

bool Form::getSign() {
    return sign;
}

int Form::getGradeToSign() {
    return grade_to_sign;
}

int Form::getGradeToExc() {
    return grade_to_exc;
}

void Form::beSigned(Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > grade_to_sign )
        throw Form::GradeTooLowException();
    sign = true;
}

Form::~Form(){}

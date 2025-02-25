#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target)
    : AForm("ShrubberyCreationForm", 145, 137), target(_target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& cpy) : AForm(cpy) {
    target = cpy.target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& cpy) {
    if (this != &cpy) {
        target = cpy.target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!getSign())
        throw FormIsNotSigned();
    if (executor.getGrade() > getGradeToExc())
        throw GradeTooLowException();
    else {
        std::ofstream file(target + "_shrubbery");
        if (!file.is_open())
            throw std::runtime_error("Failed to open file.");
        file << "                                                          .\n";
        file << "                                              .         ;  \n";
        file << "                 .              .              ;%     ;;   \n";
        file << "                   ,           ,                :;%  %;   \n";
        file << "                    :         ;                   :;%;'     .,   \n";
        file << "           ,.        %;     %;            ;        %;'    ,;\n";
        file << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
        file << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n";
        file << "               ;%;      %;        ;%;        % ;%;  ,%;'\n";
        file << "                `%;.     ;%;     %;'         `;%%;.%;'\n";
        file << "                 `:;%.    ;%%. %@;        %; ;@%;%'\n";
        file << "                    `:%;.  :;bd%;          %;@%;'\n";
        file << "                      `@%:.  :;%.         ;@@%;'   \n";
        file << "                        `@%.  `;@%.      ;@@%;         \n";
        file << "                          `@%%. `@%%    ;@@%;        \n";
        file << "                            ;@%. :@%%  %@@%;       \n";
        file << "                              %@bd%%%bd%%:;     \n";
        file << "                                #@%%%%%:;;\n";
        file << "                                %@@%%%::;\n";
        file << "                                %@@@%(o);  . '         \n";
        file << "                                %@@@o%;:(.,'         \n";
        file << "                            `.. %@@@o%::;         \n";
        file << "                               `)@@@o%::;         \n";
        file << "                                %@@(o)::;        \n";
        file << "                               .%@@@@%::;         \n";
        file << "                               ;%@@@@%::;.          \n";
        file << "                              ;%@@@@%%:;;;. \n";
        file << "                          ...;%@@@@@%%:;;;;,..\n";
    
        file.close();
    }
}
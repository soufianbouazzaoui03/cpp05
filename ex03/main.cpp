#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);
        Intern someRandomIntern;

        AForm* rrf;
        rrf = someRandomIntern.makeForm("shrubbery Creation", "Bender");
        boss.signForm(*rrf);
        boss.executeForm(*rrf);    
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
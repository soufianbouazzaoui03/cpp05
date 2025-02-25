#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);

        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << "\n--- Signing Forms ---" << std::endl;
        boss.signForm(shrubbery);
        boss.signForm(robotomy);
        boss.signForm(pardon);

        std::cout << "\n--- Executing Forms ---" << std::endl;
        boss.executeForm(shrubbery);
        boss.executeForm(robotomy);
        boss.executeForm(pardon);

        std::cout << "\n--- Intern trying to execute ---" << std::endl;
        intern.executeForm(shrubbery);
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
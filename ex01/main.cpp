#include "Bureaucrat.hpp"
#include "Form.hpp"


int main() {
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);

        Form contract("Important Contract", 50, 100);
        std::cout << contract << std::endl;

        std::cout << "\n--- Signing Attempt by Boss ---" << std::endl;
        boss.signForm(contract);
        std::cout << contract << std::endl;

        std::cout << "\n--- Signing Attempt by Intern (should fail) ---" << std::endl;
        intern.signForm(contract);
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
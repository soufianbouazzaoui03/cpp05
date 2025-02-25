#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat b1("John", 1);
        std::cout << b1 << std::endl;

        Bureaucrat b2("Jane", 2);
        std::cout << b2 << std::endl;
        b2.increment();
        std::cout << "After increment: " << b2 << std::endl;
        b2.decrement();
        std::cout << "After decrement: " << b2 << std::endl;

        Bureaucrat b3("Invalid", 0);  // Should throw GradeTooHighException
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b4("Invalid", 151);  // Should throw GradeTooLowException
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
#include<iostream>
#include <stdexcept>
#include <string>

class DivideByZeroException : public std::runtime_error {
public:
DivideByZeroException() : std::runtime_error("Error: Division by zero is not allowed.") {}
};

class InvalidOperationException : public std::runtime_error {
public:
    InvalidOperationException() : std::runtime_error("Error: Invalid operation.") {}
};

double calculate(double a, double b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                throw DivideByZeroException();
            }
            return a / b;
        default:
            throw InvalidOperationException();
    }
}

int main() {
    double num1, num2;
    char operation;
    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;
    std::cout << "Enter operation (+, -, *, /): ";
    std::cin >> operation;
    try {
    double result = calculate(num1, num2, operation);
    std::cout << "Result: " << result << std::endl;
    }
    catch (const DivideByZeroException& ex) {
    std::cerr << ex.what() << std::endl;
    }
    catch (const InvalidOperationException& ex) {
    std::cerr << ex.what() << std::endl;
    }
    catch (...) {
    std::cerr << "Unknown error occurred" << std::endl;
    }
    std::cout << "Program completed" << std::endl;
    return 0;
    }
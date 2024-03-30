#include <iostream>

using namespace std;

int main() {
    char operation;
    double num1, num2, result;

    // Input two numbers
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    // Input operation
    cout << "Enter operation (+, -, *, /): ";
    cin >> operation;

    // Perform operation based on user input
    switch(operation) {
        case '+':
            result = num1 + num2;
            cout << "Result: " << num1 << " + " << num2 << " = " << result;
            break;
        case '-':
            result = num1 - num2;
            cout << "Result: " << num1 << " - " << num2 << " = " << result;
            break;
        case '*':
            result = num1 * num2;
            cout << "Result: " << num1 << " * " << num2 << " = " << result;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result: " << num1 << " / " << num2 << " = " << result;
            } else {
                cout << "Error! Division by zero.";
            }
            break;
        default:
            cout << "Invalid operation!";
    }

    return 0;
}
